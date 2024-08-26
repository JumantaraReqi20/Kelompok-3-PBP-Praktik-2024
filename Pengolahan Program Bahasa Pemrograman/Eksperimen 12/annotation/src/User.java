public class User {
    @Validate(rule = "notEmpty")
    private String username;

    @Validate(rule = "minLength:8")
    private String password;

    // Constructor
    public User(String username, String password) {
        this.username = username;
        this.password = password;
    }
}