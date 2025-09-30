#include <stdio.h>
typedef struct Node
{
    int coeff;
    int exp;
    struct Node* prev;
    struct Node* next;
} Node;
Node* createNode(int coeff, int exp)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->prev = newNode->next = NULL;
    return newNode;
}
void insertTerm(Node** head, int coeff, int exp)
{
    if (coeff == 0) return;
    Node* newNode = createNode(coeff, exp);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    if (exp > temp->exp)
    {
        newNode->next = temp;
        temp->prev = newNode;
        *head = newNode;
        return;
    }
    while (temp->next != NULL && temp->next->exp > exp)
        temp = temp->next;
    if (temp->next != NULL && temp->next->exp == exp)
    {
        temp->next->coeff += coeff;
        free(newNode);
        if (temp->next->coeff == 0)
        {
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            if (toDelete->next != NULL)
                toDelete->next->prev = temp;
            free(toDelete);
        }
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
}
void displayPolynomial(Node* head)
{
    if (head == NULL)
    {
        printf("0\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL)
    {
        if (temp->coeff > 0 && temp != head)
            printf("+");
        if (temp->exp == 0)
            printf("%d ", temp->coeff);
        else if (temp->exp == 1)
            printf("%dx ", temp->coeff);
        else
            printf("%dx^%d ", temp->coeff, temp->exp);
        temp = temp->next;
    }
    printf("\n");
}
Node* addPolynomials(Node* poly1, Node* poly2)
{
    Node* result = NULL;
    Node* p1 = poly1;
    Node* p2 = poly2;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp > p2->exp)
        {
            insertTerm(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else if (p1->exp < p2->exp)
        {
            insertTerm(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
        else
        {
            int sumCoeff = p1->coeff + p2->coeff;
            if (sumCoeff != 0)
                insertTerm(&result, sumCoeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1 != NULL)
    {
        insertTerm(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        insertTerm(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    return result;
}
void freePolynomial(Node* head)
{
    Node* temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
Node* inputPolynomial()
{
    int n, coeff, exp;
    Node* poly = NULL;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    printf("Enter terms (coeff exponent) in any order:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly, coeff, exp);
    }
    return poly;
}
int main()
{
    printf("Input first polynomial:\n");
    Node* poly1 = inputPolynomial();
    printf("First polynomial: ");
    displayPolynomial(poly1);
    printf("\nInput second polynomial:\n");
    Node* poly2 = inputPolynomial();
    printf("Second polynomial: ");
    displayPolynomial(poly2);
    Node* sum = addPolynomials(poly1, poly2);
    printf("\nSum of polynomials: ");
    displayPolynomial(sum);
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(sum);
    return 0;
}
