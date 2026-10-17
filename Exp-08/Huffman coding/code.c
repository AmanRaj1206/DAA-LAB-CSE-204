#include <stdio.h>

#define MAX 20

struct Node
{
    char ch;
    int freq;
    int left, right;
};

struct Node tree[MAX];
int nodeCount = 0;
long long totalBits = 0;

int createNode(char ch, int freq, int left, int right)
{
    tree[nodeCount].ch = ch;
    tree[nodeCount].freq = freq;
    tree[nodeCount].left = left;
    tree[nodeCount].right = right;

    return nodeCount++;
}

void printCodes(int root, char code[], int top)
{
    if (tree[root].left == -1 && tree[root].right == -1)
    {
        code[top] = '\0';

        printf("    %c\t\t   %d\t\t%s\n",
               tree[root].ch, tree[root].freq, code);

        totalBits += (long long)tree[root].freq * 100 * top;
        return;
    }

    if (tree[root].left != -1)
    {
        code[top] = '0';
        printCodes(tree[root].left, code, top + 1);
    }

    if (tree[root].right != -1)
    {
        code[top] = '1';
        printCodes(tree[root].right, code, top + 1);
    }
}

int main()
{
    char characters[] = {'a', 'c', 'd', 'e', 'o',
                         'm', 's', 't', 'u'};

    int frequencies[] = {20, 11, 2, 10, 15,
                         8, 10, 22, 2};

    int n = 9;
    int active[MAX] = {0};

    for (int i = 0; i < n; i++)
    {
        int index = createNode(characters[i],
                               frequencies[i], -1, -1);
        active[index] = 1;
    }

    int remaining = n;

    while (remaining > 1)
    {
        int min1 = -1, min2 = -1;

        for (int i = 0; i < nodeCount; i++)
        {
            if (active[i])
            {
                if (min1 == -1 ||
                    tree[i].freq < tree[min1].freq)
                {
                    min2 = min1;
                    min1 = i;
                }
                else if (min2 == -1 ||
                         tree[i].freq < tree[min2].freq)
                {
                    min2 = i;
                }
            }
        }

        int newNode = createNode(
            '\0',
            tree[min1].freq + tree[min2].freq,
            min1, min2
        );

        active[min1] = 0;
        active[min2] = 0;
        active[newNode] = 1;

        remaining--;
    }

    int root = nodeCount - 1;
    char code[MAX];

    printf("Huffman Codes:\n");
    printf("Character\tFrequency\tCode\n");

    printCodes(root, code, 0);

    printf("\nTotal Encoded Size: %lld bits\n", totalBits);
    printf("Memory Required: %.2f bytes\n", totalBits / 8.0);

    return 0;
}
