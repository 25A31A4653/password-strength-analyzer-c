#include <stdio.h>
#include <ctype.h>

int main() {
    char password[100];
    int length = 0;
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    int score = 0;

    printf("Enter password: ");
    scanf("%s", password);

    // Calculate length
    while (password[length] != '\0') {
        length++;
    }

    // Check characters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) hasUpper = 1;
        else if (islower(password[i])) hasLower = 1;
        else if (isdigit(password[i])) hasDigit = 1;
        else hasSpecial = 1;
    }

    // Scoring system
    if (length >= 8) score++;
    if (hasUpper) score++;
    if (hasLower) score++;
    if (hasDigit) score++;
    if (hasSpecial) score++;

    // Display score
    printf("\nPassword Score: %d/5\n", score);

    // Strength level
    if (score <= 2) {
        printf("Strength: Weak\n");
    } else if (score == 3 || score == 4) {
        printf("Strength: Medium\n");
    } else {
        printf("Strength: Strong\n");
    }

    // Suggestions
    printf("\nSuggestions:\n");

    if (length < 8)
        printf("- Increase length to at least 8 characters\n");
    if (!hasUpper)
        printf("- Add uppercase letters\n");
    if (!hasLower)
        printf("- Add lowercase letters\n");
    if (!hasDigit)
        printf("- Add numbers\n");
    if (!hasSpecial)
        printf("- Add special characters\n");

    return 0;
}
