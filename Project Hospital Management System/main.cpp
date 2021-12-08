#include <iostream>
#include <fstream>
 #include <stdlib.h>

using namespace std;

// Declaring the important functions ath the top
void LandingPage();
class Patient;

// Pages for screens
void loopApp(){
     system("PAUSE");
     system("CLS");
     LandingPage();
}

// Classes needed by the software


class Patient{
     public:
          string Name;
          string SName;
          int age;
          bool Gender;
          string PhoneNumber;
          string DateOfBirth;

     void addPatient(){
          cout << "Enter the Patient's first name" << endl;
          cin >> Name;


          cout << "Enter the Patient's last name" << endl;
          cin >> SName;
 
          cout << "Enter the Patient's age" << endl;
          cin >> age;

          cout << "Enter the Patient's Gender (1) for a Male and (2) for a Female" << endl;
          int g; cin >> g;
          if(g == 1){Gender = true;}else{Gender = false;}

          cout << "Enter the Patient's Date of Birth in the format [date/month/year]" << endl;
          cin >>  DateOfBirth;

          cout << "Enter the Patient's Mobile Number" << endl;
          cin >> PhoneNumber;

          ofstream AddPatient("Patients/"+Name+".txt");
          AddPatient << Name << endl;
          AddPatient << SName << endl;
          AddPatient << age << endl;
          AddPatient << Gender << endl;   
          AddPatient << PhoneNumber << endl; 
          AddPatient << DateOfBirth << endl;

           cout << "Patient added successfully" << endl;

          AddPatient.close(); 
          loopApp();
     }
};

class Doctor{
    public:
        int id;
        string Name;
        string OfficeNumber;
        string specialization;
        bool available;

     void addDoctor(int id, string Name, string OfficeNumber, string specialization){
         
               ofstream AddDoctor("doctors/"+to_string(id)+".txt");
               AddDoctor << available << endl; 
               AddDoctor << Name << endl;
               AddDoctor << OfficeNumber << endl;
               AddDoctor << specialization << endl;   
          
               AddDoctor.close();

               loopApp();    
          
     }


     void availableDoctors(){
     //    VShow the list of doctors which first line is available [true]
     int i = 0;
     while(i<5){
          ifstream GetDoctor("doctors/"+to_string(i)+".txt");

          string line;
          getline(GetDoctor, line);
          
          if(line == "1"){

               cout << " " << endl;
               cout << "Doctor " << i << endl;
               cout << " " << endl;

               getline(GetDoctor, line);
               cout << line << endl;
               getline(GetDoctor, line);
               cout << line << endl;
               getline(GetDoctor, line);
               cout << line << endl;
          }
          i++;  
     }
     cout << "Do you want to assign a patient to a doctor? (1) for yes, (2) for no" << endl;
          int option; cin >> option;
          if(option == 1){
               // Function to add a patient
               cout << "Enter the Patient's first name" << endl;
               string name; cin >> name;

               fstream pat("Patients/"+name+".txt");
               if(pat.is_open()){
                    cout << "Patient found" << endl;
                    cout << "Enter the Doctor's ID" << endl;
                    
                    int id; cin >> id;
                    fstream doc("doctors/"+to_string(id)+".txt");
                    if(doc.is_open()){
                         cout << "Doctor found" << endl;

                         // 0
                         // Dr. Paul Sam
                         // Rm. 37
                         // Gynecologist

                         string i, n, rm, sp;
                         getline(doc, i);
                         getline(doc, n);
                         getline(doc, rm);
                         getline(doc, sp);
        
                         cout << "Patient "<< name << " assigned to " << n << " in "<< rm << endl;
                    }else{
                         cout << "Doctor not found" << endl;
                    }
               }else{
                    loopApp();
               }
     
          }
     };
};

class Diagnosis{
     public: 
          void history(){
               cout << "Enter the first name of the patient" << endl; 
               string id; cin >> id;

               ifstream pfile("patients/"+ id + ".txt");
               if(pfile.is_open()){
                    // system("CLS");
                    string line;
                    while(getline(pfile, line)){
                         cout << line << endl;
                    }
               }else{
                    cout << "Patient is not regstered on the platform" << endl; 
               }

               loopApp();
               
          };
          void addDiagnosis(){
               cout << "Enter the patient's first name" << endl;
               string name; cin >> name;

               fstream pfile("patients/"+ name + ".txt");
               if(pfile.is_open()){
                    string diagnosis;
                    
                    cout << "Add diagnosis for " << name << endl;
                    cin >> diagnosis;
                    pfile << diagnosis << endl;

                    cout << "Successfully added the diagnosis for " << name << endl;
                    pfile.close();                             
               }else{
                    cout << "Sorry, Patient is not regstered on the platform" << endl;
                    addDiagnosis();
               }
               
          };
};

     // The home screen that display all the options our software can peroform
void aboutHospital(){
    fstream f("about.txt", ios::in);
     string line;

     if(f.is_open()){
         while(getline(f, line)){
             cout << line << endl;
         }
          f.close();
     }else{
         cout << "Error opening file" << endl;   
     }
     loopApp();   
}

void LandingPage(){
     int option;
          
     cout << "Enter the option you want:" << endl;
     cout << "1. Add a new patient" << endl;
     cout << "2. View Patient Record" << endl;
     cout << "3. View available doctors" << endl;
     cout << "4. About Hospital" << endl;
     cout << "5. Exit" << endl;
    

     cin >> option;

     switch (option) {
     case 1:{
          cout << "Add a new patient" << endl;
          
          Patient NewPatient;
          NewPatient.addPatient();
          break;
     }
     case 2:
          cout << "View Patient Record" << endl;
          
          Diagnosis D;
          D.history();
          break;
     case 3:{
          
          Doctor doc;
          doc.availableDoctors();

          break;
     }
     case 4:
          
          aboutHospital();
          break;
     case 5:
          cout << "Are you sure you want to exit app Yes(1) No(2)?" << endl;
          int op; cin >> op;
          if(op == 1){
               cout << "Thank you for using our software" << endl;
               exit(0);
          }else{
               loopApp();
          }

          break;
     default :
         cout << "Invalid input, enter another option" << endl;
         loopApp();
     }
    
}



void welcome(){
     string pass;
     bool login = false;
     cout << "Welcome to Hospital Management System" << endl;

     while (login == false){
          cout << "Please enter the password: " << endl;
          cin >> pass;
          if (pass == "1407"){
               login = true;
               cout << "Access Granted" << endl;
               LandingPage();
          }
          else{
               cout << "Access Denied" << endl;
          }
     }
}

int main(){
     // system("COLOR 3F");
         
     welcome();
// int number = 15;
//      for (int i = 1; i <= number; i++) {
//         for (int j = 1; j <= number; j++) {
//             if (i == 1 || i == number || j == 1 || j == number){
//                 printf("* ");
//             }else{
//                 printf("  ");
//             }
//         }
//           cout << "\n";
//         }

     return 0;
}