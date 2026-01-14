
__asm void PendSV_Handler(void)
{
    IMPORT p_block  /* 声明 p_block 是在 C 代码中定义的全局变量，汇编中需引用 */
    

    LDR R0, =p_block  /* 将 p_block 的&zwnj;**地址**&zwnj;加载到 R0 寄存器（即获取指针变量的地址） */
    LDR R0, [R0]  /* 从 R0 指向的地址（即 p_block 的值）读取数据 → 得到第一个指针指向的地址 */
    LDR R0, [R0]  /* 再次从 R0 指向的地址读取数据 → 得到最终的目标数据 */

    STMDB R0!, {R4-R11}
    

    LDR R1, =p_block
    LDR R1, [R1] 
    STR R0, [R1]

    ADD R4, R4, #1
    ADD R5, R5, #1

    LDMIA R0!, {R4-R11}

    BX LR
}

