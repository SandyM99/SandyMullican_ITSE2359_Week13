# **Train Scheduling System**

## **Problem Statement**
The Train Scheduling System manages train schedules efficiently by:
- **Queue**: Managing upcoming train schedules in the order they are added (FIFO).  
- **Stack**: Tracking completed train routes, where the most recently completed route is accessed first (LIFO).  
- **File Persistence**: Ensuring the train schedule and completed routes are saved to files (`queue.txt` and `stack.txt`) and reloaded when the program restarts.

This program allows users to:
1. Add trains to a schedule.
2. View the next train to depart.
3. Mark a train as completed.
4. Save and reload the train data.

---

## **How It Works**

### **Data Structures**
- **Queue**: Used to store upcoming train schedules. Trains are added to the back of the queue and processed from the front.  
- **Stack**: Stores completed train routes. The last completed train route is accessible first.  

### **File Persistence**
- **`queue.txt`**: Saves the current state of the queue. Each train's details are stored in the order they are queued.  
- **`stack.txt`**: Saves the state of the stack. The most recently completed train route is saved at the bottom for correct restoration.

When the program starts:
- The queue and stack states are loaded from `queue.txt` and `stack.txt`.

When the program exits:
- The current states of the queue and stack are saved to their respective files.

---

## **Instructions to Run the Program**

### **Prerequisites**
- C++ compiler (e.g., g++, available via GCC).
- Text editor or IDE to view and edit code.

### **Steps to Compile and Run**
1. **Compile the Program**  
   Open a terminal in the project directory and run:  
   ```bash
   g++ -o TrainScheduler main.cpp TrainScheduler.cpp
