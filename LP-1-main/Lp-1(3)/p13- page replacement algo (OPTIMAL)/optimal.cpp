#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int numberOfFrames, numberOfPages, flag1, flag2, flag3, i, j, k, pos = 0, max;
    int faults = 0;

    cout << "Enter number of Frames: ";
    cin >> numberOfFrames;
    vector<int> frame(numberOfFrames, -1);

    cout << "Enter number of Pages: ";
    cin >> numberOfPages;

    vector<int> pages(numberOfPages);
    cout << "Enter the pages: ";
    for (i = 0; i < numberOfPages; i++)
        cin >> pages[i];

    vector<int> temp(numberOfFrames, -1);

    for (i = 0; i < numberOfPages; ++i) {
        flag1 = flag2 = 0;

        for (j = 0; j < numberOfFrames; ++j) {
            if (frame[j] == pages[i]) {
                flag1 = flag2 = 1;
                break;
            }
        }

        if (flag1 == 0) {
            for (j = 0; j < numberOfFrames; ++j) {
                if (frame[j] == -1) {
                    faults++;
                    frame[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }
        }

        if (flag2 == 0) {
            flag3 = 0;

            for (j = 0; j < numberOfFrames; ++j) {
                temp[j] = -1;

                for (k = i + 1; k < numberOfPages; ++k) {
                    if (frame[j] == pages[k]) {
                        temp[j] = k;
                        break;
                    }
                }
            }

            for (j = 0; j < numberOfFrames; ++j) {
                if (temp[j] == -1) {
                    pos = j;
                    flag3 = 1;
                    break;
                }
            }

            if (flag3 == 0) {
                max = temp[0];
                pos = 0;

                for (j = 1; j < numberOfFrames; ++j) {
                    if (temp[j] > max) {
                        max = temp[j];
                        pos = j;
                    }
                }
            }

            frame[pos] = pages[i];
            faults++;
        }

        cout << "frame: ";
        for (j = 0; j < numberOfFrames; ++j) {
            cout << "\t" << frame[j];
        }
        cout << "\n";
    }

    cout << "\n\nTotal Page Faults: " << faults << endl;

    return 0;
}
