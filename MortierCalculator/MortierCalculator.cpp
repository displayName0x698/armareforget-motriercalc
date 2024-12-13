#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <locale.h>

double calculate_mils(double distance, int mortar_type) {
    double mils_values_rus[] = {
        1439, // 300 метров
        1418, // 400 метров
        1398, // 500 метров
        1376, // 600 метров
        1355, // 700 метров
        1333, // 800 метров
        1311, // 900 метров
        1288, // 1000 метров
        1265, // 1100 метров
        1240, // 1200 метров
        1215, // 1300 метров
        1189, // 1400 метров
        1161, // 1500 метров
        1133, // 1600 метров
        1102, // 1700 метров
        1069, // 1800 метров
        1034, // 1900 метров
        995,  // 2000 метров
        950,  // 2100 метров
        896,  // 2200 метров
        820   // 2300 метров
    };

    double mils_values_us[] = {
        1531, // 400 метров
        1514, // 500 метров
        1496, // 600 метров
        1478, // 700 метров
        1460, // 800 метров
        1442, // 900 метров
        1424, // 1000 метров
        1405, // 1100 метров
        1385, // 1200 метров
        1366, // 1300 метров
        1346, // 1400 метров
        1326, // 1500 метров
        1305, // 1600 метров
        1283, // 1700 метров
        1261, // 1800 метров
        1238, // 1900 метров
        1214, // 2000 метров
        1188, // 2100 метров
        1162, // 2200 метров
        1134, // 2300 метров
        1104, // 2400 метров
        1070, // 2500 метров
        1034, // 2600 метров
        993,  // 2700 метров
        942,  // 2800 метров
        870   // 2900 метров
    };

    double distances[] = {
        300, 400, 500, 600, 700, 800, 900, 1000,
        1100, 1200, 1300, 1400, 1500, 1600, 1700,
        1800, 1900, 2000, 2100, 2200, 2300,
        2400, 2500, 2600, 2700, 2800, 2900
    };

    int num_points = sizeof(distances) / sizeof(distances[0]);

    for (int i = 0; i < num_points; i++) {
        if (distance == distances[i]) {
            return mortar_type == 0 ? mils_values_rus[i] : mils_values_us[i - 1];
        }
    }

    for (int i = 0; i < num_points - 1; i++) {
        if (distance > distances[i] && distance < distances[i + 1]) {
            return mortar_type == 0 ? mils_values_rus[i] - (mils_values_rus[i] - mils_values_rus[i + 1]) * (distance - distances[i]) / (distances[i + 1] - distances[i])
                : mils_values_us[i] - (mils_values_us[i] - mils_values_us[i + 1]) * (distance - distances[i]) / (distances[i + 1] - distances[i]);
        }
    }

    return -1;
}

double calculate_flight_time(double distance, int mortar_type) {
    double flight_time_values_rus[] = {
        32.9, // 400 метров
        32.9, // 500 метров
        32.8, // 600 метров
        32.7, // 700 метров
        32.6, // 800 метров
        32.4, // 900 метров
        32.2, // 1000 метров
        32.1, // 1100 метров
        31.8, // 1200 метров
        31.6, // 1300 метров
        31.3, // 1400 метров
        31.0, // 1500 метров
        30.7, // 1600 метров
        30.3, // 1700 метров
        29.8, // 1800 метров
        29.3, // 1900 метров
        28.7, // 2000 метров
        27.9, // 2100 метров
        26.9, // 2200 метров
        25.3  // 2300 метров
    };

    double flight_time_values_us[] = {
        36.3, // 400 метров
        36.2, // 500 метров
        36.2, // 600 метров
        36.1, // 700 метров
        36.0, // 800 метров
        35.9, // 900 метров
        35.8, // 1000 метров
        35.7, // 1100 метров
        35.6, // 1200 метров
        35.4, // 1300 метров
        35.3, // 1400 метров
        35.1, // 1500 метров
        34.9, // 1600 метров
        34.6, // 1700 метров
        34.4, // 1800 метров
        34.1, // 1900 метров
        33.8, // 2000 метров
        33.5, // 2100 метров
        33.1, // 2200 метров
        32.7, // 2300 метров
        32.2, // 2400 метров
        31.7, // 2500 метров
        31.0, // 2600 метров
        30.3, // 2700 метров
        29.2, // 2800 метров
        27.7  // 2900 метров
    };

    double distances[] = {
        300, 400, 500, 600, 700, 800, 900, 1000,
        1100, 1200, 1300, 1400, 1500, 1600, 1700,
        1800, 1900, 2000, 2100, 2200, 2300,
        2400, 2500, 2600, 2700, 2800, 2900
    };

    int num_points = sizeof(distances) / sizeof(distances[0]);

    for (int i = 0; i < num_points; i++) {
        if (distance == distances[i]) {
            return mortar_type == 0 ? flight_time_values_rus[i] : flight_time_values_us[i];
        }
    }

    for (int i = 0; i < num_points - 1; i++) {
        if (distance > distances[i] && distance < distances[i + 1]) {
            return mortar_type == 0 ? flight_time_values_rus[i] - (flight_time_values_rus[i] - flight_time_values_rus[i]) * (distance - distances[i]) /
                (distances[i + 1] - distances[i])
                : flight_time_values_us[i] - (flight_time_values_us[i] - flight_time_values_us[i]) * (distance - distances[i]) / (distances[i + 1] - distances[i]);
        }
    }

    return -1;
}

int main() {
    double distance;
    int mortar_type;
    int lang;
    printf("Select Lang (0 - RU, 1 - ENG): ");
    scanf("%d", &lang);

    if (lang == 0) {
        setlocale(LC_ALL, "RU");
    }

    printf(lang ? "Choose a mortar (0 - RU, 1 - US): " : "Выберите миномет (0 - RU, 1 - US): ");
    scanf("%d", &mortar_type);

    if (mortar_type < 0 || mortar_type > 1) {
        printf(lang ? "select 0 or 1.\n" : "выберите 0 или 1.\n");
        system("pause");
        exit(-1);
    }

    printf(lang ? "Enter the range in meters (300 to 2900): " : "Введите дальность в метрах (от 300 до 2900): ");
    scanf("%lf", &distance);

    if (distance < 300 || distance > 2900) {
        printf(lang ? "value in the range of 300 to 2900 meters." : "значение в диапазоне от 300 до 2900 метров.\n");
        system("pause");
        exit(-1);
    }

    double mils = calculate_mils(distance, mortar_type);
    double flight_time = calculate_flight_time(distance, mortar_type);

    if (mils == -1 || flight_time == -1) {
        printf(lang ? "out-of-range distance.\n" : "расстояние вне диапазона.\n");
    }
    else {
        printf(lang ? "Flight time: \033[31m%.2f\033[0m sec. : mils: \033[31m%.2f \033[0m\n" : "Время полета: \033[31m%.2f\033[0m сек. : Миль: \033[31m%.2f \033[0m\n", flight_time, mils);
    }

    system("pause");
    exit(-1);
}