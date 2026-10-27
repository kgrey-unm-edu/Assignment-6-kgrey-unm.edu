#include <iostream>
#include <cstdlib>
#include <ctime>
#include "coordinate.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Usage: "
             << argv[0]
             << " number_of_coordinates\n";
        return 1;
    }

    int numCoordinates = atoi(argv[1]);

    Coordinate *head = nullptr;
    Coordinate *tail = nullptr;

    srand(time(nullptr));

    // Create random coordinates
    for (int i = 0; i < numCoordinates; i++)
    {
        float x = rand() % 100;
        float y = rand() % 100;

        add_coordinate(head, tail, x, y);
    }

    cout << "List Length: "
         << list_length(head)
         << endl;

    forward_display(head);

    backward_display(tail);

    // Delete coordinate with ID 3
    cout << "\nDeleting coordinate ID 3\n";
    delete_coordinate(head, tail, 3);

    forward_display(head);

    // Find coordinate closest to (50, 50)
    closest_to(head, 50.0f, 50.0f);

    // Free remaining memory
    while (head != nullptr)
    {
        Coordinate *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
