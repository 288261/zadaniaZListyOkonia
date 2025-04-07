#include <stdio.h>

int main()
{
    char *source_code = "#include <stdio.h>\n\nint main() {\n    // Definicja ciągu zawierającego kod źródłowy programu\n    char *source_code = ";

    printf("WYŚWIETLANIE PROGRAMU ŹRÓDŁOWEGO\n");

    printf("%s\"%s\";\n    printf(\"WYŚWIETLANIE PROGRAMU ŹRÓDŁOWEGO\\n\");\n    printf(\"%%s\", source_code); \n    return 0;\n}", source_code, source_code);

    return 0;
}