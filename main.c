#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int ret_ft, ret_std;

    // Geçersiz format: %q
    ret_ft = ft_printf("Invalid format: %q\n");
    ret_std = printf("Invalid format: %q\n");
    printf("[%%q] Return -> ft_printf: %d | printf: %d\n\n", ret_ft, ret_std);

    // Geçersiz format: %z
    ret_ft = ft_printf("Invalid format: %z\n");
    ret_std = printf("Invalid format: %z\n");
    printf("[%%z] Return -> ft_printf: %d | printf: %d\n\n", ret_ft, ret_std);

    // Yanlış kullanılmış % işareti (tek başına %)
    ret_ft = ft_printf("Incomplete percent: %");
    ret_std = printf("Incomplete percent: %");
    printf("\n[Incomplete %%] Return -> ft_printf: %d | printf: %d\n\n", ret_ft, ret_std);

    return 0;
}
