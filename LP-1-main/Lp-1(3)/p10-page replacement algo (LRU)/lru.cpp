#include <iostream>
using namespace std;

int main() {
    int f, page = 0, ch, pgf = 0, n, chn = 0;
    bool flag;
    int *pages; // pgf - page fault

    cout << "1.LRU" << endl;
    int pt = 0;
    cout << "enter no. of frames: ";
    cin >> f;

    int *frame = new int[f];

    for (int i = 0; i < f; i++) {
        frame[i] = -1;
    }

    cout << "enter the no of pages: ";
    cin >> n;

    pages = new int[n];
    cout << "enter the page no: ";

    for (int j = 0; j < n; j++)
        cin >> pages[j];

    int pg = 0;
    for (pg = 0; pg < n; pg++) {
        page = pages[pg];
        flag = true;
        for (int j = 0; j < f; j++) {
            if (page == frame[j]) {
                flag = false;
                break;
            }
        }

        int temp, h = 3, i;
        if (flag) {

            if (frame[1] != -1 && frame[2] != -1 && frame[0] != -1) {
                temp = pages[pg - 3];
                if (temp == pages[pg - 2] || temp == pages[pg - 1])
                    temp = pages[pg - 4];

                for (i = 0; i < f; i++)
                    if (temp == frame[i])
                        break;
                frame[i] = pages[pg];
            } else {
                if (frame[0] == -1)
                    frame[0] = pages[pg];
                else if (frame[1] == -1)
                    frame[1] = pages[pg];
                else if (frame[2] == -1)
                    frame[2] = pages[pg];
            }

            cout << "frame: ";
            for (int j = 0; j < f; j++)
                cout << frame[j] << " ";
            cout << endl;
            pgf++;
        } else {
            cout << "frame: ";
            for (int j = 0; j < f; j++)
                cout << frame[j] << " ";
            cout << endl;
        }
    }

    cout << "Page fault: " << pgf << endl;

    delete[] frame;
    delete[] pages;

    return 0;
}
