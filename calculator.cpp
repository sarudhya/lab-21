#include <windows.h>
#include <cstdio>

HWND textfield, button, TextBox1, TextBox2;
char textSaved1[50];
char textSaved2[50];
char result[50];
double x,y,sum;

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {


    switch(Message) {
        case WM_CREATE:
            textfield = CreateWindow("STATIC", "   Please input two numbers",
                WS_VISIBLE | WS_CHILD | WS_BORDER, 20, 20, 200, 25, hwnd, NULL, NULL, NULL);

            button = CreateWindow("BUTTON", "+",
                WS_VISIBLE | WS_CHILD | WS_BORDER, 30, 120, 30, 30, hwnd, (HMENU)1, NULL, NULL);

            button = CreateWindow("BUTTON", "-",
                WS_VISIBLE | WS_CHILD | WS_BORDER, 75, 120, 30, 30, hwnd, (HMENU)2, NULL, NULL);

            button = CreateWindow("BUTTON", "*",
                WS_VISIBLE | WS_CHILD | WS_BORDER, 125, 120, 30, 30, hwnd, (HMENU)3, NULL, NULL);

            button = CreateWindow("BUTTON", "/",
                WS_VISIBLE | WS_CHILD | WS_BORDER, 175, 120, 30, 30, hwnd, (HMENU)4, NULL, NULL);

            TextBox1 = CreateWindow("EDIT", "", WS_CHILD | WS_VISIBLE,
                25, 55, 190, 20, hwnd, NULL, NULL, NULL);
			
			TextBox2 = CreateWindow("EDIT", "", WS_CHILD | WS_VISIBLE,
				25, 85, 190, 20, hwnd, NULL, NULL, NULL);
            break;

        case WM_COMMAND:
            switch (LOWORD(wParam)) {
                case 1: 
                    GetWindowText(TextBox1, textSaved1, sizeof(textSaved1)); 
					GetWindowText(TextBox2, textSaved2, sizeof(textSaved2));
					x = atof(textSaved1);
					y = atof(textSaved2);
					sum = x+y;
					sprintf(result, "%lf", sum);
                    MessageBox(hwnd, result, "Result", MB_OK); 
                    break;
                case 2: 
                    GetWindowText(TextBox1, textSaved1, sizeof(textSaved1)); 
					GetWindowText(TextBox2, textSaved2, sizeof(textSaved2));
					x = atof(textSaved1);
					y = atof(textSaved2);
					sum = x-y;
					sprintf(result, "%lf", sum);
                    MessageBox(hwnd, result, "Result", MB_OK); 
                    break;
                case 3: 
                    GetWindowText(TextBox1, textSaved1, sizeof(textSaved1)); 
					GetWindowText(TextBox2, textSaved2, sizeof(textSaved2));
					x = atof(textSaved1);
					y = atof(textSaved2);
					sum = x*y;
					sprintf(result, "%lf", sum);
                    MessageBox(hwnd, result, "Result", MB_OK); 
                    break;
                case 4: 
                    GetWindowText(TextBox1, textSaved1, sizeof(textSaved1)); 
					GetWindowText(TextBox2, textSaved2, sizeof(textSaved2));
					x = atof(textSaved1);
					y = atof(textSaved2);
					sum = x/y;
					sprintf(result, "%lf", sum);
                    MessageBox(hwnd, result, "Result", MB_OK); 
                    break;
                
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, Message, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wc;
    HWND hwnd;
    MSG msg;

    memset(&wc, 0, sizeof(wc));
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = CreateSolidBrush(RGB(228, 173, 196));
    wc.lpszClassName = "WindowClass";
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, "WindowClass", "My Calculator",
        WS_VISIBLE | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT, 250, 200,
        NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) {
        MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}