#include <iostream>
#include <cmath>
#include "coordinate.h"

using namespace std;

int list_length(Coordinate *list_beginning)
{
    int count = 0;

    Coordinate *current = list_beginning;

    while (current != nullptr)
    {
        count++;
        current = current->next;
    }

    return count;
}

void add_coordinate(Coordinate *&list_beginning,
                    Coordinate *&list_end,
                    float x,
                    float y)
{
    Coordinate *newNode = new Coordinate;

    newNode->x = x;
    newNode->y = y;
    newNode->next = nullptr;
    newNode->previous = nullptr;

    newNode->coord_id = list_length(list_beginning) + 1;

    if (list_beginning == nullptr)
    {
        list_beginning = newNode;
        list_end = newNode;
    }
    else
    {
        list_end->next = newNode;
        newNode->previous = list_end;
        list_end = newNode;
    }
}

void forward_display(Coordinate *list_beginning)
{
    Coordinate *current = list_beginning;

    cout << "\nFORWARD DISPLAY\n";

    while (current != nullptr)
    {
        cout << "ID: " << current->coord_id
             << " (" << current->x
             << ", " << current->y << ")\n";

        current = current->next;
    }
}

void backward_display(Coordinate *list_end)
{
    Coordinate *current = list_end;

    cout << "\nBACKWARD DISPLAY\n";

    while (current != nullptr)
    {
        cout << "ID: " << current->coord_id
             << " (" << current->x
             << ", " << current->y << ")\n";

        current = current->previous;
    }
}

void delete_coordinate(Coordinate *&list_beginning,
                       Coordinate *&list_end,
                       int coord_id_to_delete)
{
    Coordinate *current = list_beginning;

    while (current != nullptr)
    {
        if (current->coord_id == coord_id_to_delete)
        {
            if (current->previous != nullptr)
            {
                current->previous->next = current->next;
            }
            else
            {
                list_beginning = current->next;
            }

            if (current->next != nullptr)
            {
                current->next->previous = current->previous;
            }
            else
            {
                list_end = current->previous;
            }

            delete current;

            cout << "\nCoordinate "
                 << coord_id_to_delete
                 << " deleted.\n";

            return;
        }

        current = current->next;
    }

    cout << "\nCoordinate not found.\n";
}

void closest_to(Coordinate *list_beginning,
                float x,
                float y)
{
    if (list_beginning == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }

    Coordinate *current = list_beginning;
    Coordinate *closest = current;

    float minDistance =
        sqrt(pow(current->x - x, 2) +
             pow(current->y - y, 2));

    current = current->next;

    while (current != nullptr)
    {
        float distance =
            sqrt(pow(current->x - x, 2) +
                 pow(current->y - y, 2));

        if (distance < minDistance)
        {
            minDistance = distance;
            closest = current;
        }

        current = current->next;
    }

    cout << "\nPoint searched from: ("
         << x << ", " << y << ")\n";

    cout << "Closest coordinate:\n";
    cout << "ID: " << closest->coord_id
         << " (" << closest->x
         << ", " << closest->y << ")\n";

    cout << "Distance = "
         << minDistance << endl;
}
