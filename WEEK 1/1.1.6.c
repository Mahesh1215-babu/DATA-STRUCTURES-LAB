#include <stdio.h>
};

// Function to convert temperature and print the result
void convertTemperature(struct TemperatureData data) {
    float convertedTemp;

    if (data.scale == CELSIUS) {
		float fahrenheit = (data.value.celsius * 9 / 5 )+ 32;
        // convertedTemp = data.value.celsius * 9 / 5 + 32;
        printf("%.2f degrees Celsius is %.2f degrees Fahrenheit.\n",data.value.celsius,fahrenheit );
    } else {
        // convertedTemp = (data.value.fahrenheit - 32) * 5 / 9;
		float celsius= (data.value.fahrenheit - 32) * 5 / 9;
        printf("%.2f degrees Fahrenheit is %.2f degrees Celsius.\n",data.value.fahrenheit,celsius);
    }
}

int main() {
    // Example usage with user input
    struct TemperatureData tempData;

    printf("Enter temperature value: ");
    scanf("%f", &tempData.value.celsius);
    
    printf("Choose scale (0 for Celsius, 1 for Fahrenheit): ");
    scanf("%d", (int*)&tempData.scale);

    // Validate the scale input
    if (tempData.scale != CELSIUS && tempData.scale != FAHRENHEIT) {
        printf("Invalid scale choice.\n");
        return 1; // Exit with an error code
    }

    // Convert temperature and print result
    convertTemperature(tempData);

    return 0;
}
