#include <stdio.h>
#include <stdlib.h>
int copy_file(const char *src, const char *dest) {
FILE *source = fopen(src, "rb");
if (source == NULL) {
perror("Error opening source file");
return 1;
}
FILE *destination = fopen(dest, "wb");
if (destination == NULL) {
perror("Error opening destination file");
fclose(source);
return 1;
}
char buffer[1024];
size_t bytes;
while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0) {
fwrite(buffer, 1, bytes, destination);
}
fclose(source);
fclose(destination);
return 0;
}
int main() {
const char *filename = "file.txt";
const char *copyname = "file_copy.txt";
const char *movedname = "file_moved.txt";
FILE *fp = fopen(filename, "w");
if (fp == NULL) {
perror("Error creating file");
return 1;
}
fprintf(fp, "This is a test file.\n");
fclose(fp);
printf("File created: %s\n", filename);
if (copy_file(filename, copyname) == 0) {
printf("File copied to: %s\n", copyname);
} else {printf("Failed to copy file.\n");
}
if (rename(copyname, movedname) == 0) {
printf("File moved/renamed to: %s\n", movedname);
} else {
perror("Error moving file");
}
if (remove(filename) == 0) {
printf("Original file deleted: %s\n", filename);
} else {
perror("Error deleting original file");
}
return 0;
}
