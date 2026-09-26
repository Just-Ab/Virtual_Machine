# Virtual Machine Design

- Project aimed to improve project control and scope limitation.

## What Am I Building?
- A virtual machine capable of executing bytecode programs loaded from a 256-byte unified memory space, using an explicit fetch–decode–execute
  model with a fixed-size instruction fetch queue.


## Scope
- Implement Main Sequence Registers.
- Memory Loading To Register.
- Memory Storing From Register.
- Executing Opcode From Memory.

## In-Depth
### Registers-8-Bits
    -Instruction Pointer.
    -Stack Pointer.
    -Index Source.
    -Accumulator.
    -Secondary.
### Memory-Concept
    -Memory is a flat 256bytes array.
    -Memory holds both Code and Data.

## Start-Up
- Initialize the VM, will dive deep in that later.
- Loads the 256-bytes flat binary to the unified memory.
- start Execution.

## Code-Execution
### Fetch-Queue
    -Instruction Fetch Unit loads bytes from Memory through IP and loads to the Fetch Queue.
    -Fetch Queue is bound to 6 bytes, respecting the i8086 architecture.
### Decoding
    -Decoder decodes the content of the byte pointed by the Fetch Index.
### Execution
    -Execute the instruction raised by the Decoder.

## Code
### Modules
    -VM.
    -CPU.
    -Memory.

    -Fetch Unit.
    -Decoder Unit.
    -Execution Unit.

### Macros
    -Binary Loader.

### Definition
    -VM:
        -Init VM.
        -Run VM.
        -Step VM.
        -Stop VM.
        -Load Rom.
        
    -CPU:
        -Init CPU.
        -Run CPU.
        -Step CPU.
        -Stop CPU.
        -Advance IP.
        -Peek Fetch Queue.
        -Advance Fetch Queue Head.
        -Peek Register.
        -Load Register.

    -Memory:
        -Init Memory.
        -Read Memory.
        -Write Memory.
        
    -Fetch Unit:
        -Step Fetch.

    -Decoder Unit:
        -step Decode.

    -Execution Unit:
        -Step Execute.

    -Program Loader:
        -Load Program.

###Instructions

    - Arithmetic Instructions:
        -MOV REG,REG
        -MOV REG,IMM
        ------------
        -ADD REG,REG
        -ADD REG,IMM
        ------------
        -SUB REG,REG
        -SUB REG,IMM
        ------------
        -AND REG,REG
        -AND REG,IMM
        ------------
        -OR REG,REG
        -OR REG,IMM
        ------------
        -XOR REG,REG
        -XOR REG,IMM
        ------------



    - Stack
        -PUSH REG
        -PUSH IMM
        ------------
        -POP REG
    
# Notice

## Math library

- Routine "neg" idiomatic




# ASSEMBLER

## How should it work

- Parse text based on spacing, link each word to the instruction listed in "ISA", if not available debugger should trigger a notice else should pass, at the end of the string, the decoder should set a hlt instruction even when the code does implement a halt instruction above, the data should be read from an asm file and written to a bin or iso file. 

## Modules

- Debugger 
- Logger
- Fetcher
- Decoder
- File writer