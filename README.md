# 🧘‍♂️ Philosophers

## 📌 Project Overview

**Philosophers** is a **42 School** project that explores multithreading and process synchronization by simulating the famous **Dining Philosophers Problem**. The goal is to manage multiple philosophers who eat, think, and sleep without encountering **deadlocks** or **race conditions**.

This project enhances your understanding of **threads**, **mutexes**, and **synchronization mechanisms** in concurrent programming.

---

## 🚀 Features

✅ Multi-threaded simulation of philosophers  
✅ Proper synchronization using **mutexes**  
✅ Avoids deadlocks and race conditions  
✅ Handles different numbers of philosophers  
✅ Monitors starvation and ensures program termination  
✅ Error handling for invalid inputs  

---

## 🔧 Installation & Usage

### 1️⃣ Clone the Repository
```sh
git clone https://github.com/bou1337/philosophers-42.git
cd philosophers-42
```

### 2️⃣ Compile the Program
```sh
make
```

### 3️⃣ Run the Simulation
```sh
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
Example:
```sh
./philo 5 800 200 200
```
This starts a simulation with **5 philosophers**, where:
- `800ms` is the time before a philosopher dies without eating.
- `200ms` is the time it takes for a philosopher to eat.
- `200ms` is the time a philosopher spends sleeping.

---

## 🔍 How Philosophers Works

### 1️⃣ The Dining Philosophers Problem
The problem consists of **N** philosophers sitting around a circular table. Each philosopher follows these steps:
1. Think 🤔
2. Pick up forks 🍴 (shared resources)
3. Eat 🍝
4. Put down forks 🍴
5. Sleep 💤

The challenge is to prevent deadlocks and starvation while ensuring all philosophers get a chance to eat.

### 2️⃣ Synchronization Mechanisms
To manage shared resources and avoid race conditions, **mutexes** are used:
- Each fork is protected by a **mutex**.
- A mutex ensures that only one philosopher can pick up a fork at a time.
- A monitoring thread checks if any philosopher starves and stops the simulation if needed.

---

## 🔗 Resources & References
- **[Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)**
- **[Multithreading in C](https://man7.org/linux/man-pages/man3/pthread_create.3.html)**
- **[42 Project Subject](https://github.com/bou1337/philosophers)**

