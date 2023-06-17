# Oladoc-_Find-and-book-the-best-doctors-near-you
oladoc is a digital healthcare platform in Pakistan. It helps you find and instantly book appointments or
online video consultations with the best doctors in Pakistan. Their transparent and intuitive platform helps
you choose the right doctors by letting you check up on patient reviews, consultation fees, satisfaction
scores, and wait times. oladoc has already served over 15 million+ patients across the country and
counting. Now assuming you want to build the console based system by implementing the oladoc system
with some additional functionalities in c++.
Following are the main Module of Oladoc
1. Appointment Management Module
2. Doctor Schedule Management Module
3. Patient Management Module
4. Doctor Management Module
5. Login Module
6. Registration Module
This system has three users. Admin, Doctor, and Patient. So all feature has been divided between these
three users.
![WhatsApp Image 2023-06-17 at 8 24 04 PM](https://github.com/Zamehi/Oladoc-_Find-and-book-the-best-doctors-near-you/assets/129313428/33844fd3-1f14-4bdf-8a69-dd6118e74ba4)


o Admin can Add Edit Delete and view Doctor’s data.
o Admin can view all patient’s data.
o Admin can Schedule any Doctor Availability and manage that data like edit or delete it.
o Admin can view all doctor appointment data and he or she can also process appointments
(update or cancel).
Doctor Users
o Doctor can register into this system.
o Doctor can log in to this system.
o Doctor can Add, Edit and Delete their availability and hourly charge.
o Doctor can view only their appointment data; they cannot see other doctor appointment data.
o Doctor can check the appointment patient’s details.
o Doctors must have their particular specialization areas
o To each area, there must be a separate/distinct view and possibly sub-views
o Doctor can change the status the of appointment as approve, pending and reject. Initially, the
status of all the appointments request will be pending until Doctor confirms the request as
approved.
o Doctor can edit his profile details (timing, location, rates, etc.).
o Doctor can check all his scheduled appointments in his profile.
Patients Users
o Patient can register into this system.
o Patient can log in to this system.
o Patient can reset the password.
o Patient can search for doctors by (Specialty, Area, and Hospitals)
o Patient can check Doctor’s availability and chargers.
o Patient can book and cancel the appointment with Doctor.
o Patient can update the appointment details (only the scheduled time).
o Patient can change their profile details.
o Patient can Book in-person or video consultations with the Doctor.
o Patient can check all his scheduled appointments in his profile.
o Patient can recharge their account

Registration/Signup 10 Marks
Registration details are stored in three separate txt/dat files namely admin, doctor, and patient. These
files have User details. Note: carefully analyze and select the attributes that need to be stored in these
files.
• Doctor Panel:
o A new doctor can register in the system with a valid CNIC or email.
The doctor account is only created if a valid 13-digit CNIC is provided. CNIC and email
must not be repeated in the existing record. Otherwise, appropriate messages should be
generated to notify the users.
o Password must be 8 characters long and the use of a minimum of one special character,
uppercase, lowercase, and the numeric digit is a must.
o While registration the system should verify any typing mistake in password by asking the
user to re-enter the password.
o After successful registration, the system will ask for details about the doctor e.g Years of
experience, his specialization area, the hospital name he is working in, availability hours
for an appointment, and city (Can be more attributes as per the requirements of the
system)
• Patient Panel:
o A new patient can register into the system with a valid CNIC.
o The patient account is only created if a valid 13-digit CNIC is provided and CNIC must not
be repeated in the existing record. Otherwise, appropriate messages should be
generated to notify the users.
o Password must be 8 characters long and the use of a minimum of one special character,
uppercase, lowercase, and the numeric digit is a must.
o Patient must re-enter the password and the system should verify any typing mistake.
o After successful registration, the initial balance for each patient will be Rs. 3500.
Login 10 marks
• Admin Panel
o Admin can login to the system by predefined username and password
o Display proper error message in case of wrong credentials.
• Doctor Panel
o A doctor can log in to the system by the username and password provided at the time of
registration.
o Display proper error message in case of wrong credentials.
• Patient Panel
o A patient can log in to the system by the username and password provided at the time
of registration.
o Display proper error message in case of wrong credentials.

Menu 20 Marks
A menu is provided to each user (Admin, doctor, patient) separately to navigate the full system.
• After completion of each step, users are provided with a menu for the subsequent process and a
link to the main menu (different menu for the different users e.g. Admin, patient, doctor).
• Basic details about the system are available for every user without login. System-specific details
like Book appointments, Cancellation, check availability, etc. are only accessible to the
registered users.
Book Appointment 40 Marks
There are many ways a patient can find a doctor to book an appointment
• Patient can find a doctor via his/her specialty (categories) like dermatologist, neurologist, etc
• Patient can also find doctors via hospital name or city
• Your system cannot book 2 appointments for the same doctor at the same time.
• Before booking an appointment, display a list of day and hours slots and the charges that are
available for the doctor.
• Charges for in-person and video consultation appointments are different for each Doctor.
• Patient can check all his booked appointments and their status in his profile
• Maintain a separate file to store the appointment information which will include Doctor CNIC,
Doctor name, Patient CNIC, patient name, appointment mode, day, and time.
• For appointment cancellation, do the required implementation as well (think about it how will
you reflect in the system that the appointment is canceled and it is no more scheduled)

Feedback 20 Marks
o After a checkup/appointment, a feedback menu should be displayed on the patient’s account
o The new displayed menu should be used to write a review + give a rating (out of 5 stars) about
the doctor
o Feedback rating must be maintained based on patients’ reviews about the doctor
o The feedback must be shown on the concerned doctor’s profile
o The overall ratings that would be displayed on the doctor’s profile must be the average of all the
ratings which will never exceed length 5
o Bonus: A reply on the review of patients from the management can also be implemented

Payment 20 Marks
The payment details for each booked appointment are recorded. Appointment charges for all the
appointments are displayed to the users.
• Charges for in-person and video consultation appointments are different for each Doctor.
• The system must calculate the charges by keeping in mind that video consultation is 70% of the
in-person appointment charges (30% less).
• As the payment is a transaction from the doctor’s account to the patient’s account, the return
would be the inverse of the transaction
• The patient should be able to select an E-Gateway for the transaction such as JazzCash,
EasyPaisa, PayPak, UnionPay or Bank Transfer
• Set a criterion for if the patient does not show up on the date of appointment, a percentage
would be deducted from the amount he paid + he would have to pay that percentage again
o -30% after one day

E.g., 100 already paid for an appointment, 30 would he pay if come a day later

o -60% after two days (Patient would have to pay 60% extra)

E.g., 100 already paid for an appointment, 60 would he pay if come a day later

o -100% on three days (Patient would have to fix the appointment again)
E.g., 100 already paid for an appointment, the patient would re-fix an
appointment and would have to pay 100 again if he comes after three days

• In case the patient wants to cancel the appointment
o 100% return on the same day of fixing the appointment
o 60% return on the second day of fixing the appointment
o 30% return on the third day of fixing the appointment
o No return after the third day

Note
• Your program should never exit. Always display a menu to the user.
• All the operations are done via file handling so no need to log out from one user and go back to
another using only one console, your program must be able to run multiple consoles using the
same code and same file paths.
• After completion of each step, users are provided with a menu for the subsequent process and a
link to the main menu (different menu for the different users e.g. Admin, patient, doctor)
• Also, provide the functionality of Logout to each user.
• Solid marks for building a proper hierarchy for modules(folders), classes(files) and user
interfaces
