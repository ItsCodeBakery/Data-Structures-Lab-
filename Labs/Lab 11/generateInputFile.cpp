#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

// Arrays for generating realistic Muslim names
string firstNamesMale[] = {
    "Muhammad", "Ahmed", "Ali", "Omar", "Hassan", "Hussein", "Yousuf", "Ibrahim",
    "Ismail", "Khalid", "Bilal", "Usman", "Hamza", "Tariq", "Saad", "Zain",
    "Faisal", "Junaid", "Imran", "Kamran", "Adnan", "Arslan", "Asad", "Fahad",
    "Haris", "Salman", "Tahir", "Waleed", "Yasir", "Zubair", "Aamir", "Shahid",
    "Farhan", "Rizwan", "Nadeem", "Rashid", "Sami", "Talha", "Umar", "Waqar",
    "Abdullah", "Abdul Rahman", "Abdul Aziz", "Azhar", "Haider", "Haseeb", "Jawad", "Karim",
    "Luqman", "Majid", "Naveed", "Omer", "Qasim", "Raza", "Saqib", "Shayan",
    "Taha", "Usama", "Yahya", "Zakariya", "Amjad", "Aslam", "Bashir", "Danish",
    "Ehsan", "Furqan", "Ghulam", "Irfan", "Jamil", "Kashif", "Latif", "Mubarak",
    "Nasir", "Osama", "Pervez", "Qadir", "Rafiq", "Shahzad", "Tanvir", "Wasim"
};

string firstNamesFemale[] = {
    "Fatima", "Aisha", "Maryam", "Zainab", "Khadija", "Hafsa", "Ruqayyah", "Sana",
    "Sara", "Hira", "Amina", "Noor", "Huda", "Layla", "Mariam", "Zara",
    "Ayesha", "Bushra", "Farah", "Hana", "Iqra", "Javeria", "Kanza", "Lubna",
    "Mahnoor", "Nimra", "Rabia", "Sadia", "Tayyaba", "Warda", "Zahra", "Aliza",
    "Arooj", "Esha", "Farida", "Haleema", "Ifra", "Kinza", "Madiha", "Nida",
    "Qurat", "Rida", "Saima", "Tooba", "Uzma", "Yumna", "Zoya", "Anam",
    "Fizza", "Hajra", "Kubra", "Mehreen", "Nazia", "Rafia", "Samina", "Shazia",
    "Sehrish", "Sidra", "Anum", "Areeba", "Faiza", "Huma", "Iram", "Maha",
    "Naila", "Rema", "Sabeen", "Sehar", "Ayat", "Dua", "Emaan", "Fariha",
    "Ghazala", "Hiba", "Insha", "Mahira", "Nayab", "Rani", "Sumaya", "Tania"
};

string lastNames[] = {
    "Khan", "Ahmed", "Ali", "Hassan", "Shah", "Malik", "Hussain", "Mahmood",
    "Rahman", "Siddiqui", "Akhtar", "Aziz", "Baig", "Chaudhry", "Dar", "Farooq",
    "Haider", "Iqbal", "Javed", "Karim", "Mirza", "Naqvi", "Qureshi", "Raza",
    "Saeed", "Tariq", "Usman", "Yousuf", "Zaidi", "Abbasi", "Butt", "Cheema",
    "Durrani", "Gillani", "Hashmi", "Jamil", "Kazmi", "Leghari", "Mughal", "Niazi",
    "Pasha", "Quershi", "Rizvi", "Shafi", "Tahir", "Waheed", "Zia", "Ansari",
    "Bhatti", "Farooqui", "Haq", "Ilyas", "Khalil", "Latif", "Masood", "Nadeem",
    "Qadir", "Rasheed", "Saleem", "Tahir", "Wali", "Zaman", "Afridi", "Baloch",
    "Ghazi", "Hafeez", "Imam", "Junaid", "Kamal", "Lodhi", "Mufti", "Nasir",
    "Osmani", "Pirzada", "Rana", "Sultan", "Tanveer", "Usmani", "Warraich", "Yasin",
    "Akram", "Bashir", "Daud", "Fahim", "Ghani", "Hameed", "Ismail", "Kamran",
    "Majeed", "Naveed", "Rafiq", "Sadiq", "Shakeel", "Wahab", "Yaqoob", "Zaheer",
    "Anwar", "Farhan", "Hamza", "Irfan", "Kareem", "Manzoor", "Naseer", "Pervez",
    "Ramzan", "Shafiq", "Tirmizi", "Uzair", "Waqar", "Younas", "Zahid", "Aslam"
};

string departments[] = { "CSE", "EEE", "MEC", "CIV", "ARC", "CHE", "BBA", "ECO", "PHY", "MAT" };

// Function to generate random CGPA with realistic distribution
double generateCGPA() {
    int rand_val = rand() % 100;
    if (rand_val < 5) return 2.00 + (rand() % 50) / 100.0;  // 5% below 2.50
    else if (rand_val < 20) return 2.50 + (rand() % 50) / 100.0;  // 15% between 2.50-3.00
    else if (rand_val < 50) return 3.00 + (rand() % 30) / 100.0;  // 30% between 3.00-3.30
    else if (rand_val < 80) return 3.30 + (rand() % 40) / 100.0;  // 30% between 3.30-3.70
    else return 3.70 + (rand() % 30) / 100.0;  // 20% between 3.70-4.00
}

// Function to generate credit hours based on semester
int generateCreditHours(int semester) {
    int baseCredits = semester * 18;  // Assuming ~18 credits per semester
    int variation = rand() % 21 - 10;  // Random variation of -10 to +10
    int credits = baseCredits + variation;
    if (credits < 15) credits = 15;  // Minimum credits
    if (credits > 195) credits = 195;  // Maximum for 8th semester
    return credits;
}

int main() {
    srand(time(0));

    ofstream outFile("students_data.txt");

    if (!outFile) {
        cout << "Error creating file!" << endl;
        return 1;
    }

    const int TOTAL_STUDENTS = 1000000;

    cout << "Generating 1,000,000 student records..." << endl;
    cout << "This may take a few minutes. Please wait..." << endl;

    // Write total count
    outFile << TOTAL_STUDENTS << endl;

    int maleNameSize = sizeof(firstNamesMale) / sizeof(firstNamesMale[0]);
    int femaleNameSize = sizeof(firstNamesFemale) / sizeof(firstNamesFemale[0]);
    int lastNameSize = sizeof(lastNames) / sizeof(lastNames[0]);
    int deptSize = sizeof(departments) / sizeof(departments[0]);

    // Generate records
    for (int i = 0; i < TOTAL_STUDENTS; i++) {
        // Generate unique Student ID (6 digits starting from 200001)
        int studentID = 200001 + i;

        // Generate random name (50% male, 50% female)
        string firstName;
        if (rand() % 2 == 0) {
            firstName = firstNamesMale[rand() % maleNameSize];
        }
        else {
            firstName = firstNamesFemale[rand() % femaleNameSize];
        }

        string lastName = lastNames[rand() % lastNameSize];
        string fullName = firstName + " " + lastName;

        // Generate random department
        string dept = departments[rand() % deptSize];

        // Generate random semester (1-8)
        int semester = (rand() % 8) + 1;

        // Generate CGPA
        double cgpa = generateCGPA();

        // Generate credit hours based on semester
        int creditHours = generateCreditHours(semester);

        // Generate enrollment year (2015-2023)
        int enrollmentYear = 2015 + (rand() % 9);

        // Write to file
        outFile << studentID << " "
            << fullName << " "
            << dept << " "
            << semester << " "
            << fixed << setprecision(2) << cgpa << " "
            << creditHours << " "
            << enrollmentYear << endl;

        // Progress indicator
        if ((i + 1) % 100000 == 0) {
            cout << "Generated " << (i + 1) << " records..." << endl;
        }
    }

    outFile.close();

    cout << "\n==================================================" << endl;
    cout << "SUCCESS! File 'students_data.txt' created!" << endl;
    cout << "Total records: " << TOTAL_STUDENTS << endl;
    cout << "==================================================" << endl;

    // Display file statistics
    cout << "\nFile Statistics:" << endl;
    cout << "- Student IDs: 200001 to " << (200000 + TOTAL_STUDENTS) << endl;
    cout << "- Departments: 10 different departments" << endl;
    cout << "- Semesters: 1 to 8" << endl;
    cout << "- CGPA Range: 2.00 to 4.00" << endl;
    cout << "- Enrollment Years: 2015 to 2023" << endl;
    cout << "\nYou can now use this file with your linked list program!" << endl;

    return 0;
}
