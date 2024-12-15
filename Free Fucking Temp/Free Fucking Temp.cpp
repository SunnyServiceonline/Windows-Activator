#include <iostream>
#include "Windows.h" 
#include <cstdlib>  // Für system()
#include <tlhelp32.h>
#include <string>
#include <vector>

void spoofingisdone() {
    system("cls");
    std::cout << "yeah and now ur spoofed have fun # TOMATOWARE ON TOP\n"; 
    std::cout << "Closing in 5 secs\n";
    Sleep(5000);
    exit(0);
}

void setConsoleGreen() {
    // Setzt die Konsolenfarbe auf Grün
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
}
void setConsoleRed() {
    // Setzt die Konsolenfarbe auf Rot
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
}

void resetConsoleColor() {
    // Setzt die Konsolenfarbe auf den Standardwert zurück
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void terminateProcess(const std::string& processName) {
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE) return;

    PROCESSENTRY32 processEntry;
    processEntry.dwSize = sizeof(PROCESSENTRY32);

    if (Process32First(hSnapshot, &processEntry)) {
        do {
            if (processName == processEntry.szExeFile) {
                HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, processEntry.th32ProcessID);
                if (hProcess) {
                    TerminateProcess(hProcess, 0);
                    CloseHandle(hProcess);
                }
            }
        } while (Process32Next(hSnapshot, &processEntry));
    }

    CloseHandle(hSnapshot);
}

void deleteFile(const std::string& filePath) {
    if (DeleteFile(filePath.c_str()) == 0) {
        std::cerr << "Failed to delete file: " << filePath << " (Error: " << GetLastError() << ")\n";
    }
}

void deleteFilesInDirectory(const std::string& directory) {
    std::string searchPath = directory + "\\*";
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile(searchPath.c_str(), &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) return;

    do {
        const std::string fileOrDir = findFileData.cFileName;
        if (fileOrDir != "." && fileOrDir != "..") {
            std::string fullPath = directory + "\\" + fileOrDir;

            if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                deleteFilesInDirectory(fullPath);
                RemoveDirectory(fullPath.c_str());
            }
            else {
                deleteFile(fullPath);
            }
        }
    } while (FindNextFile(hFind, &findFileData));

    FindClose(hFind);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void typeEffect(const std::string& text, int delay) {
    for (char c : text) {
        std::cout << c;
        Sleep(delay); // Verzögerung zwischen Buchstaben
    }
    std::cout << std::endl; // Neue Zeile nach dem Text
}

void SetConsoleColor(WORD color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Funktion zum Setzen der Konsolen-Transparenz
void SetConsoleTransparency(int transparency) {
    HWND hwnd = GetConsoleWindow();

    // Stelle sicher, dass das Fenster 'layered' ist, um Transparenz zu ermöglichen
    LONG style = GetWindowLong(hwnd, GWL_EXSTYLE);
    SetWindowLong(hwnd, GWL_EXSTYLE, style | WS_EX_LAYERED);

    // Setze die Transparenz des Fensters mit SetLayeredWindowAttributes
    SetLayeredWindowAttributes(hwnd, 0, transparency, LWA_COLORKEY); // transparency ist ein Wert von 0 bis 255
}

void openDiscordLink() {
    // Öffnet den Discord-Link im Standard-Webbrowser
    system("start https://discord.gg/DmZG2mHvVM");
}

void setConsoleYellow() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Handle für die Konsole
    SetConsoleTextAttribute(hConsole, 14);            // 14 entspricht Gelb
}
void setConsolePink() {
    SetConsoleColor(FOREGROUND_RED | FOREGROUND_BLUE); // Pink = Rot + Blau
}

void someFunction() {
    // Beispielaktion mit Ton und Rückkehr zu main
    Beep(500, 500);

    // Zurück zur Hauptfunktion
    someFunction();
}







int main()
{
  

    SetConsoleTitleA("Sunny / TomateWare Free Activator                      Made By Cr$my                                                 [ Bulid 14.12.2024 23:10 ]                      Made By Cr$my                                                 ");
    SetConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
    SetConsoleTransparency(128);
    SetConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
    std::cout << "[Info]" << std::flush;
    SetConsoleColor(FOREGROUND_BLUE);
    typeEffect(" Welcome to Sunny / TomateWare Free Activator MADE BY Cr$my", 30);
    SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    Sleep(3000);


    system("cls");
    setConsolePink();
    Beep(500, 500);
    typeEffect(" Made by Cr$my", 40);
    Sleep(5000);

    // Blaue Farbe und erste Infozeile
    SetConsoleColor(FOREGROUND_BLUE);
    typeEffect(" [Info]", 0);

    // Rote Farbe und Ladeanzeige
    SetConsoleColor(FOREGROUND_RED);
    typeEffect(" Loading the Activator", 40);
    Sleep(5000);
    setConsolePink();
    typeEffect(" Done", 40);
    Sleep(2500);
    Beep(500, 500);
    setConsoleGreen();
    std::cout << "\n\n";
    std::cout << "                             MADE BY CR$MY\n";
    std::cout << "                             MADE BY CR$MY\n";
    std::cout << "                             Made For Sunny and TomateWare           \n";
    std::cout << "                             Have Fun using PRO for Free            \n";
    std::cout << "       ______________________________________________________________\n";
    std::cout << "\n                 Activation Methods:\n\n";
    std::cout << "             [1] HWID        |  Windows           |   Working and Perm\n";
    std::cout << "             [2] Ohook       |  Office            |   Working and Perm\n";
    std::cout << "             [3] KMS38       |  Windows           |   Maybe Working and 180 Days\n";
    std::cout << "             [4] Online KMS  |  Windows / Office  |   Maybe Working and 180 Days\n";
    std::cout << "             __________________________________________________      \n\n";
    std::cout << "             [5] Check Activation Status\n";
    std::cout << "             [8] Extras\n";
    std::cout << "             [0] Exit\n";
    std::cout << "       ______________________________________________________________\n\n";

    int choice;
    std::cout << "Choose a menu option: ";
    std::cin >> choice;
    return choice;

    int option;
    std::string username;
    std::string password;
    std::string key;

    std::cin >> option;
    switch (option)
    {
    case 1:

        system("curl --silent https://files.catbox.moe/hpzd1k.cmd -o C:\\Windows\\HWID_Activation.cmd >nul");

        system("C:\\Windows\\HWID_Activation.cmd");

        std::remove("C\\Windows\\HWID_Activation.cmd");
        main();

    case 2:
        system("curl --silent https://files.catbox.moe/zj0xww.cmd -o C:\\Windows\\Ohook_Activation_AIO.cmd >nul");

        system("C:\\Windows\\Ohook_Activation_AIO.cmd");


        std::remove("C:\\Windows\\Ohook_Activation_AIO.cmd");

    


        openDiscordLink();
        main();


    case 3:
        system("curl --silent https://files.catbox.moe/uf6zg1.cmd -o C:\\Windows\\KMS38_Activation.cmd >nul");

        system("C:\\Windows\\KMS38_Activation.cmd");


        std::remove("C:\\Windows\\KMS38_Activation.cmd");



       
        openDiscordLink();
       
        main();

    case 4:
        system("curl --silent https://files.catbox.moe/cbr3yv.cmd -o C:\\Windows\\Online_KMS_Activation.cmd >nul");

        system("C:\\Windows\\Online_KMS_Activation.cmd");


        std::remove("C:\\Windows\\Online_KMS_Activation.cmd");




        openDiscordLink();

        main();

    case 5:

        exit(0);
    }
       
}


