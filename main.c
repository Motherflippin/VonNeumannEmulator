#include <stdio.h>

#define DEBUG 1
#define RAM_SIZE 32

#include "Log.h"

int main() {
    Log("PROGRAM START\n");

    Log("Creating Registers\n");
    int PC;
    int CIR;
    int MDR;
    int MAR;
    int ACC;

    Log("Initialising Registers\n");
    PC = 0;
    CIR = 0;
    MDR = 0;
    MAR = 0;
    ACC = 0;

    Log("Creating Memory\n");
    int RAM[RAM_SIZE];

    Log("Loading Instructions\n");
    enum Instructions {
        OP_OUT,
        OP_ADD,
        OP_LOAD,
        OP_PASS,
        OP_SUB,
        OP_MULTIPLY,
        OP_DIVIDE,
        OP_BRA,
        OP_BRZ,
        OP_BRP,
        OP_STORE,
        OP_INPUT,
        OP_HALT,
    };

    void Add() {
        Log("Called Add\n");
        ACC += RAM[PC];
        PC += 1;
    }

    void Output() {
        Log("Called Output\n");
        printf("%d", ACC);
        printf("\n");
    }

    void Load() {
        Log("Called Load\n");
        ACC = RAM[PC];
        PC += 1;
    }

    void UpdateState() {
        Log("Updating CPU State\n");
        PC += 1;
    }

    void Sub() {
        Log("Called Sub\n");
        ACC -= RAM[PC];
        PC += 1;
    }

    void Multiply() {
        Log("Called Multiply\n");
        ACC *= RAM[PC];
        PC += 1;
    }

    void Divide() {
        Log("Called Divide\n");
        ACC /= (int)RAM[PC];
        PC += 1;
    }

    void BRA() {
        Log("Called BRA\n");
        PC = RAM[PC];
    }

    void BRZ() {
        Log("Called BRZ\n");
        if (ACC == 0) {PC = RAM[PC];}
    }

    void BRP() {
        Log("Called BRP\n");
        if (ACC >= 0) {PC = RAM[PC];}
    }

    void Store() {
        Log("Called Store\n");
        RAM[PC] = ACC;
    }

    void Input() {
        Log("Called Input\n");
        scanf("%d", &ACC);
    }

    void Halt() {
        Log("Called Halt");
        PC = 32;
    }

    Log("Initalising Memory\n");
    for (int i = 0; i < RAM_SIZE; i++) {
        RAM[i] = OP_PASS;
    }

    RAM[0] = OP_INPUT;
    RAM[2] = OP_OUT;
    RAM[3] = OP_HALT;


    Log("Beginning Execution\n");

    while (PC < 32) {
        CIR = RAM[PC];
        UpdateState();

        switch (CIR) {
            case OP_OUT: Output(); break;
            case OP_ADD: Add(); break;
            case OP_LOAD: Load(); break;
            case OP_MULTIPLY: Multiply(); break;
            case OP_DIVIDE: Divide(); break;
            case OP_BRA: BRA(); break;
            case OP_BRZ: BRZ(); break;
            case OP_BRP: BRP(); break;
            case OP_INPUT: Input(); break;
            case OP_STORE: Store(); break;
            case OP_HALT: Halt(); break;
        }
    }

    Log("Execution Ended\n");

    return 0;
}