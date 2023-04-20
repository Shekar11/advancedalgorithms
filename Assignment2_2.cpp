#include <iostream>
using namespace std;

class Node
{
public:
    int row;
    int col;
    int data;
    Node *nxt;

    Node(int row_idx, int col_idx, int x)
    {
        row = row_idx;
        col = col_idx;
        data = x;
        nxt = NULL;
    }
};

void create_new_node(Node **ptr, int row_idx, int col_idx, int x)
{
    Node *temp = *ptr;
    Node *r;
    if (temp == NULL)
    {
        *ptr = new Node(row_idx, col_idx, x);
    }
    else
    {
        while (temp->nxt != NULL)
            temp = temp->nxt;

        r = new Node(row_idx, col_idx, x);
        temp->nxt = r;
    }
}

void print_list(Node *start)
{
    Node *p = start;
    while (p != NULL)
    {
        cout << p->row << " ";
        p = p->nxt;
    }
    cout << endl;

    p = start;
    while (p != NULL)
    {
        cout << p->col << " ";
        p = p->nxt;
    }
    cout << endl;
    p = start;

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->nxt;
    }
}

int main()
{
    int i = 0;
    int sparse_matrix[4][5] =
        {
            {0, 0, 3, 0, 4},
            {0, 0, 5, 7, 0},
            {0, 0, 0, 0, 0},
            {0, 2, 6, 0, 0}
        };

    Node *start = NULL;
    while (i < 4)
    {
        int j = 0;
        while (j < 5)
        {
            if (sparse_matrix[i][j] != 0)
                create_new_node(&start, i, j, sparse_matrix[i][j]);
            j++;
        }
        i++;
    }
    print_list(start);
}
