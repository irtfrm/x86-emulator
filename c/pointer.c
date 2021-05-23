int main(void)
{
    int a = 0;
    int* p = &a;
    *p = 20;

    int arr[10];
    arr[0] = 10;
    return *arr;
}