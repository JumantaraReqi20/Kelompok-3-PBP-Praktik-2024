

public class Main {
    public static void main(String[] args) {
        User user = new User("umar", "password123");
        ValidationProcessor.processValidations(user); // Akan mencetak pesan kesalahan sesuai validasi
    }
}
