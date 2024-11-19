// 1. Install extension
// 2. Install this and reload vs code https://code.visualstudio.com/docs/?dv=win64user
// 3. Install this and open https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbmRXRVVwV1FSUWJJazduSTRTN1pQejdPSHRYd3xBQ3Jtc0trRlFvMmpxT1k3Zm5SNEVsRWNsTWNPcHkxTXdpajAyODBGWTVsNWJvY2JVY3IwaS0yV29qSXNfdTRiVTd4Y2xFUkM3VlJQWng2R01VbTBLamFYaFF3eU1GQThSVlpNYW1ETHFESHFlbjNnZW91bFptYw&q=https%3A%2F%2Fgithub.com%2Fmsys2%2Fmsys2-installer%2Freleases%2Fdownload%2F2023-05-26%2Fmsys2-x86_64-20230526.exe&v=DMWD7wfhgNY
// 4. In Mysys run $pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
// 5. In windows search bar type environment variables to find 'edit environmental variables'
// 6. Click environmental variables
// 7. Click on path > edit > new > C:\msys64\ucrt64\bin
// 8. Restart computer

#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}