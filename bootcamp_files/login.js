document.getElementById('loginForm').addEventListener('submit', function(event) {
    event.preventDefault(); // Prevent the form from submitting
    
    // Get the input values
    var email = document.getElementById('email').value;
    var password = document.getElementById('password').value;

    // Function to validate email using a stricter regular expression
    function validateEmail(email) {
        // Regular expression yang lebih ketat untuk validasi email
        var re = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/;
        return re.test(String(email).toLowerCase());
    }

    // Basic validation
    var emailIsValid = validateEmail(email);
    var passwordIsValid = password.length > 0;

    // Show or hide error messages
    document.getElementById('emailError').classList.toggle('hidden', emailIsValid);
    document.getElementById('passwordError').classList.toggle('hidden', passwordIsValid);

    // If valid, proceed with login (for now, just console log)
    if (emailIsValid && passwordIsValid) {
        alert('Login successful!');
        console.log('Email:', email);
        console.log('Password:', password);
        // Here, you could proceed with a real login (e.g., API call)
    }
});
