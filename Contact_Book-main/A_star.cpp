#include <iostream>
#include <fstream>
using namespace std;

class A_star {
    char vertices[20];
    int n;
    int heu[20];
    int arr[20][20];

public:
    A_star() {
        n = 0;
        for (int i = 0; i < 20; i++) {
            heu[i] = 0;
            for (int j = 0; j < 20; j++) {
                arr[i][j] = 0;
            }
        }
    }

    void accept();
    void accept_file();
    void display();
};

void A_star::accept() {
    cout << "\nEnter the number of vertices: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter vertex " << i + 1 << ": ";
        cin >> vertices[i];
        cout << "Enter heuristic for vertex " << vertices[i] << ": ";
        cin >> heu[i];
    }
    cout << "Thanks for inserting the vertices\n";
    cout << "Please add the edges\n";
    char pos1, pos2;
    char ch;
    int wt;
    do {
        cout << "\nEnter the pos1: ";
        cin >> pos1;
        cout << "Enter the pos2: ";
        cin >> pos2;
        cout << "Enter the cost: ";
        cin >> wt;
        arr[pos1 - 'A'][pos2 - 'A'] = wt;
        arr[pos2 - 'A'][pos1 - 'A'] = wt;
        cout << "Do you want to continue? (Y/N): ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
}

void A_star::accept_file() {
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         arr[i][j]=0;
    //     }
    // }
    string filename = "a.txt";
    ifstream file(filename.c_str());
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }
    file >> n;
    for (int i = 0; i < n; i++) {
        file >> vertices[i];
        cout<<vertices[i]<<"  ";
    }

    for (int i = 0; i < n; i++) {
        file >> heu[i];
        cout<<heu[i]<<"  ";
    }
    
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            arr[i][j]=0;
        }
    }
    char pos1,pos2;
    int wt;
    while(file>>pos1>>pos2>>wt)
    {
        arr[pos1-'A'][pos2-'A']=wt;
        arr[pos2-'A'][pos1-'A']=wt;
        cout<<arr[0][0]<<endl;
    }
    file.close();
}

void A_star::display() {
    cout << "Vertices: ";
    for (int i = 0; i < n; i++) {
        cout << vertices[i] <<"  ";
    }
    for (int i=0;i<n;i++)
    {
        cout<<heu[i]<<"  ";
    }
    for (int i = 0; i < n; i++) {
        cout << "   ";
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }
}

int main() {
    A_star obj;
    int ch1 = 0;
    while (ch1 != 3) {
        cout << "\n1. Accept the graph\n2. Display\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch1;
        switch(ch1) {
            case 1:
                obj.accept_file();
                break;
            case 2:
                obj.display();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    }
    return 0;
}
