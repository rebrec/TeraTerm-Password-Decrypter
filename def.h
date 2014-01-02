typedef unsigned char BYTE;
typedef char CHAR;
typedef int BOOL;
typedef int INT;
typedef unsigned int UINT;
typedef CHAR* LPCHAR;
typedef CHAR* PCHAR;
typedef BYTE* LPBYTE;

#define TRUE 1;
#define FALSE 0;
#define LOWORD(a) ((WORD)(a))
#define HIWORD(a) ((WORD)(((DWORD)(a) >> 16) & 0xFFFF))

BOOL EncSeparate(PCHAR Str, int *i, LPBYTE b);
BYTE EncCharacterize(BYTE c, LPBYTE b);
void Decrypt(PCHAR InStr, PCHAR OutStr);
void Encrypt(PCHAR InStr, PCHAR OutStr);
void DecCombine(PCHAR Str, int *i, BYTE b);
BYTE DecCharacter(BYTE c, LPBYTE b);


