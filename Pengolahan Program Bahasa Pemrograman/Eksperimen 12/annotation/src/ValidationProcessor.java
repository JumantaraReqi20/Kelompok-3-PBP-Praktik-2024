import java.lang.reflect.Field;

public class ValidationProcessor {

    public static void processValidations(Object obj) {
        Class<?> objClass = obj.getClass();
        Field[] fields = objClass.getDeclaredFields();

        boolean allValid = true; // Flag untuk melacak apakah semua validasi berhasil

        for (Field field : fields) {
            if (field.isAnnotationPresent(Validate.class)) {
                Validate validate = field.getAnnotation(Validate.class);
                String rule = validate.rule();

                try {
                    field.setAccessible(true); // Agar dapat mengakses field private
                    Object value = field.get(obj);

                    System.out.println("Validating field: " + field.getName() + " with rule: " + rule);

                    if (rule.startsWith("minLength:")) {
                        int minLength = Integer.parseInt(rule.split(":")[1]);
                        if (value == null || value.toString().length() < minLength) {
                            System.err.println("Field " + field.getName() + " must be at least " + minLength + " characters long");
                            allValid = false; // Menandakan bahwa ada kesalahan validasi
                        }
                    } else {
                        switch (rule) {
                            case "notEmpty":
                                if (value == null || value.toString().trim().isEmpty()) {
                                    System.err.println("Field " + field.getName() + " cannot be empty");
                                    allValid = false; // Menandakan bahwa ada kesalahan validasi
                                }
                                break;

                            default:
                                System.err.println("Unknown validation rule: " + rule);
                                allValid = false; // Menandakan bahwa ada kesalahan validasi
                                break;
                        }
                    }
                } catch (IllegalAccessException e) {
                    System.err.println("Error accessing field " + field.getName() + ": " + e.getMessage());
                    allValid = false; // Menandakan bahwa ada kesalahan validasi
                }
            }
        }

        if (allValid) {
            System.out.println("All validations passed successfully!");
        }
    }
}
