# Minitalk - Process Communication Using Signals

## 📌 Description

**Minitalk** is a simple project written in **C** that demonstrates inter-process communication using UNIX signals. It consists of a **client** program that sends a string to a **server** process, which then displays the received message.

The project primarily uses the **SIGUSR1** and **SIGUSR2** signals to transmit data bit by bit between processes.

---

## 🎮 Features

-   📨 **Send strings from a client process to a server process**
-   📶 **Bitwise transmission using SIGUSR1 and SIGUSR2 signals**
-   🖨 **Server displays the received message in real-time**
-   ✅ **Acknowledgment system** to ensure correct reception of each bit
-   ❌ **Error handling** for invalid inputs

---

## 🛠 Compilation and Execution

### 🔧 **Compilation**

Compile both the server and client programs with:

```sh
make
```

### ▶️ **Execution**

#### Start the server:

```sh
./server
```

The server will display its **PID**.

#### Send a message from the client:

```sh
./client <server_pid> "Your message here"
```

-   `<server_pid>` : The PID of the running server process
-   `"Your message here"` : The message to send

Example:

```sh
./client 12345 "Hello, World!"
```

---

## ⌨️ How It Works

1. The **client** converts each character of the message into **8 bits**.
2. It sends **SIGUSR1** for `0` and **SIGUSR2** for `1` to the **server**.
3. The **server** reconstructs the characters bit by bit.
4. After receiving a character, the **server** sends an acknowledgment signal to the **client**.
5. The process continues until the entire message (including `\0` terminator) is transmitted.

---

## 📂 Project Structure

```
minitalk/
├── src/
│   ├── client.c             # Client program
│   ├── server.c             # Server program
├── includes/
│   ├── client.h             # Header file for client functions
│   ├── server.h             # Header file for server functions
├── libft/                    # Custom library (libft) for utility functions
├── Makefile                  # Compilation rules
├── README.md                 # Project documentation
```

---

## 📜 Author

-   **vbonnard** (<vbonnard@student.42perpignan.fr>)

---

## 📌 Note

This project was developed as part of **42 School**. If you encounter a bug or have suggestions, feel free to contribute! 🚀
