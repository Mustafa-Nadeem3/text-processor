# Text Processor

## Introduction

This C++ Text Processor is a versatile program designed to perform a wide range of text-related tasks, from reading and writing paragraphs to more advanced functions like encryption, compression, and spellchecking. The program provides a user-friendly interface for processing text data efficiently and effectively.

## Features

### 1. Read and Write Paragraphs

- **Read**: The program can read a paragraph from a file using the insertion operator `>>`.
- **Write**: It can write a paragraph to a file using the extraction operator `<<`.

### 2. Display Paragraph

- The program can display the paragraph on the screen using the extraction operator `<<`.

### 3. Compare Paragraphs

- It can check if two paragraphs are equal using the `==` operator.

### 4. Convert Text Case

- The program can convert all characters of the paragraph to either UPPERCASE or lowercase. It includes a Boolean flag for case selection.
- Overloads the unary operator `+` for UPPERCASE conversion and `-` for lowercase conversion.

### 5. Character and Word Count

- Counts the number of English and Punctuation characters in the paragraph.
- Counts the number of characters in every word of every sentence.
- Counts the number of words in every paragraph and sentence. A word is terminated on a space character.
- Counts the number of sentences in the whole text and in every paragraph. A sentence is terminated on a full stop `.`.

### 6. Encrypt and Decrypt

- Encrypts the paragraph using a key contained within the text. It includes a Boolean flag for encryption.
- For encryption, the key is added to the ASCII value of each English character and Punctuation. Characters are rotated so that 'z' with a key of 2 becomes 'b'.
- Decrypts the paragraph by subtracting the key from each encrypted character.
- Overloads unary operator `%` for Encryption and `*` for Decryption.

### 7. Spellcheck

- Checks words of the paragraph against a given dictionary.
- The dictionary is a text file containing a list of words.
- Words not present in the dictionary are returned as a list of misspelled words.

### 8. Combine Paragraphs

- Adds two paragraphs into a single paragraph using the binary operator `+`.

### 9. Compression and Decompression

- Compresses the text using Huffman coding.
- Calculates the frequency of each word in the text and assigns a code to each word.
- Replaces each word in the text with the corresponding code.
- Decompresses the text by replacing each code with the corresponding word.
- Includes a Boolean flag for compression.
- Provides compression ratio after compression.
- Overloads unary operator `!` for Compression and `^` for Decompression.

## Usage

1. Compile and run the program.
2. Use the menu-driven interface to select and perform various text processing tasks.

## Contributing

Contributions are welcome! If you'd like to contribute to this project, please follow the standard GitHub fork and pull request workflow.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments

- This program was developed using C++ in Visual Studio 2022.
- We appreciate the support of the open-source community.

## Contact Information

For any questions or inquiries, please contact Mustafa Nadeem at mustafanad007@gmail.com.

Feel free to customize this README file with your name, contact information, and any additional acknowledgments or relevant details specific to your project.
