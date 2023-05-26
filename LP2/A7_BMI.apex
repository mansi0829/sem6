
public class BMICalculator {
    public static void calculateBMI(Double weight, Double height) {
        try {
            if (weight <= 0 || height <= 0) {
                throw new IllegalArgumentException('Weight and height must be positive values.');
            }

            Double bmi = weight / (height * height);
            System.debug('BMI: ' + bmi);

            String category = getCategory(bmi);
            System.debug('Category: ' + category);
        } catch (Exception e) {
            System.debug('Error calculating BMI: ' + e.getMessage());
        }
    }

    public static String getCategory(Double bmi) {
        if (bmi < 18.5) {
            return 'Underweight';
        } else if (bmi >= 18.5 && bmi < 25) {
            return 'Normal weight';
        } else if (bmi >= 25 && bmi < 30) {
            return 'Overweight';
        } else {
            return 'Obese';
        }
    }

    public static void main() {
        Double weight = 68.4;
        Double height = 1.75;
        calculateBMI(weight, height);
    }
}
