__int64 __fastcall setprotocaps(__int64 thread, __int64 caps) // derived from pseudo (reconstructed)
{
    int v2; // ebx
    __int64 v5; // rdi
    __int64 result; // rax
    int a1 = thread; // lua state pointer

    v2 = 0;

    *(DWORD64*)(a1 + 120) = caps; // L->userdata
    if (*(int*)(a1 + 148) > 0) // Proto -> sizep
    {
        v5 = 0LL;
        do
        {
            result = setprotocaps(*(DWORD64*)((*(DWORD64*)(a1 + 16) ^ (a1 + 16)) + v5), caps);
            ++v2;
            v5 += 8LL;
        } while (v2 < *(DWORD64*)(a1 + 148));
    }
    return result;
}
