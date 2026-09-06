#include <stdio.h>
#include <string.h>
#include "hello.h"

// Capture output by redirecting stdout
int main() {
    FILE *fp;
    char buffer[100];

    // Redirect stdout to a temporary file
    fp = freopen("test_output.txt", "w", stdout);
    if (!fp) {
        perror("freopen failed");
        return 1;
    }

    // Call the function under test
    print_hello();

    // Restore stdout
    freopen("/dev/tty", "w", stdout);

    // Read the output back
    fp = fopen("test_output.txt", "r");
    if (!fp) {
        perror("fopen failed");
        return 1;
    }
    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);

    // Check if output matches expected
    if (strcmp(buffer, "Hello, World!\n") == 0) {
        printf("✅ Test passed: Output is correct.\n");
        return 0;
    } else {
        printf("❌ Test failed: Expected 'Hello, World!' but got '%s'\n", buffer);
        return 1;
    }
}
