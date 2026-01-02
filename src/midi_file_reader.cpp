#include <fstream>
#include <iostream>
#include <string>



int main(){
    // Select file by inserting name here
    std::string fileName = "wolf.mid";
    std::ifstream midiFile;
    midiFile.open(fileName, std::ios::binary | std::ios::in | std::ios::ate);
    if (!midiFile){
        std::cout << "ERROR OPENING FILE";
        return 1;
    }

    char* mem_block;
    size_t size = midiFile.tellg();
    mem_block = new char[size];
    midiFile.seekg(0, std::ios::beg);
    midiFile.read(mem_block, size);
    midiFile.close();

    unsigned char* mem_block_u = reinterpret_cast<unsigned char *>(mem_block);

    int size_s = 0;
    // Note
    for (int i = 0; i < size; i++){
        if ((int)mem_block_u[i] == 144){
            printf("%d, ", mem_block_u[i + 1]);
            size_s++;
        }
    }
    printf("\n\n");
    // Timing
    for (int i = 0; i < size; i++){
        if((int)mem_block_u[i] == 144){
            printf("%d, ", mem_block_u[i + 4]);
        }
    }
    printf("\nArray size: %d\n", size_s);
   
    delete[] mem_block;
}