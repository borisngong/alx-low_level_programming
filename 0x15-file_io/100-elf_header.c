#include "main.h"

void display_elf_abi_version(unsigned char *e_ident);
void validate_elf_identification(unsigned char *e_ident);
void display_elf_class(unsigned char *e_ident);
void display_elf_magic(unsigned char *e_ident);
void display_elf_data(unsigned char *e_ident);
void display_elf_version_info(unsigned char *e_ident);
void display_elf_file_type(unsigned int e_type, unsigned char *e_ident);
void display_elf_osabi(unsigned char *e_ident);
void display_elf_abi_version(unsigned char *e_ident);
void display_entry_point_address(unsigned long int e_entry, unsigned char *e_ident);

/**
  * validate_elf_identification - verify the ELF identification bytes to
  * determineif the provided file is valid elf.
  * @e_ident: pointer to an array of unsinged characters and array contains ELF
  * identification bytes
  * Return: void
  */
void validate_elf_identification(unsigned char *e_ident)
{
	int byte_ind;

	byte_ind = 0;

	while (byte_ind < 4)
	{
		if (e_ident[byte_ind] != 127 && e_ident[byte_ind] != 'E' &&
		    e_ident[byte_ind] != 'l' && e_ident[byte_ind] != 'f')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
	byte_ind++;
}
/**
  * display_elf_class - function serves to represent the class of an ELF file
  * base on its identification byte.
  * @e_ident: @e_ident: pointer to an array of unsinged characters and the
  * array contains ELF
  * Return: void
  */
void display_elf_class(unsigned char *e_ident)
{
	printf("Class: ");

	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		case ELFCLASS32:
			printf("ELF32");
			break;
		default:
			printf("<unknow: 0%x02x\n>", e_ident[EI_CLASS]);
	}
}
/**
  * display_elf_magic - displaying the magic bytes of an ELF in a hex format
  * @e_ident: array of unsigned characters representing the ELF identification
  * bytes
  * Return: (void)
  */
void display_elf_magic(unsigned char *e_ident)
{
	int byte_ind;

	printf("Magic: ");

	byte_ind = 0;
	while (byte_ind < EI_NIDENT)
	{
		printf("%02x", e_ident[byte_ind]);
		if (byte_ind == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
		byte_ind++;
	}


}
/**
  * display_elf_data - for displaying data encoding type of ELF file
  * @e_ident: pointer to an array containin the ELF identification bytes
  * Return: void
  */
void display_elf_data(unsigned char *e_ident)
{
	printf("Data: ");

	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, little endian");
			break;
		default:
			printf("<unknown: 0%x02x>\n", e_ident[EI_CLASS]);
	}
}
/**
  * display_elf_version_info - responsible for displaying
  * version of ELF file format
  * @e_ident: allos function to access the header and retrieve version
  * information
  * Return: void
  */
void display_elf_version_info(unsigned char *e_ident)
{
	printf(" Version: %d", e_ident[EI_VERSION]);

	if (e_ident[EI_VERSION] == EV_CURRENT)
	{
		printf(" (current)\n");
	}
	else if (e_ident[EI_VERSION] == EV_NONE)
	{
		printf(" (none)\n");
	}
	else
	{
		printf("\n");
	}
}
/**
  * display_elf_file_type - display file type with error handling
  * @e_ident: pointer to array representing elf identification header
  * @e_type: unsigned int value that specifies the file type
  * Return: void
  */
void display_elf_file_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf(" File Type: ");

	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
	case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
	case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
	case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
	case ET_CORE:
			printf("CORE (Core file)\n");
			break;
	default:
			printf("<unknown %x>\n", e_type);
	}
}
/**
  * display_elf_osabi - reponsible for displaying OS/ABI information of
  * Elf file
  * @e_ident: pointer to an array representing the ELF identification
  * header
  * Return: void
  */
void display_elf_osabi(unsigned char *e_ident)
{
	printf(" OS/ABI: ");

	if (e_ident[EI_OSABI] == ELFOSABI_NONE)
	{
		printf("UNIX - System V\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_HPUX)
	{
		printf("UNIX - HP-UX\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_NETBSD)
	{
		printf("UNIX - NetBSD\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_LINUX)
	{
		printf("UNIX - Linux\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_SOLARIS)
	{
		printf("UNIX - Solaris\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_IRIX)
	{
		printf("UNIX - IRIX\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_FREEBSD)
	{
		printf("UNIX - FreeBSD\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_TRU64)
	{
		printf("UNIX - TRU64\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_ARM)
	{
		printf("ARM\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_STANDALONE)
	{
		printf("Standalone App\n");
	}
	else
	{
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}
/**
  * display_elf_abi_version - responsible for displaying the abi version
  * of an ELF file
  * @e_ident: pointer to array of unsigned characters representing the
  * ElF identification header
  * Return: void
  */
void display_elf_abi_version(unsigned char *e_ident)
{
	printf(" ABI Version: %d\n", e_ident[EI_ABIVERSION]);
}
/**
  * display_entry_point_address - purpose is to handle the printing of
  * entry pointaddress, considering class and endianess of ELF file
  * @e_ident: pointer to an array of unsighed char values
  * @e_entry: represents the entry point address of ELF file
  */
void display_entry_point_address(unsigned long int e_entry, unsigned char *e_ident)
{
    printf("Entry point address: ");

    if (e_ident[EI_DATA] == ELFDATA2MSB)
    {
        e_entry = ((e_entry << 8) & 0xFF00FF00) |
                  ((e_entry >> 8) & 0xFF00FF);
        e_entry = (e_entry << 16) | (e_entry >> 16);
    }

    if (e_ident[EI_CLASS] == ELFCLASS32)
        printf("%#x\n", (unsigned int)e_entry);
    else
        printf("%#lx\n", e_entry);
}
/**
  * main - Entry point of the programm
  * @__attribute__((__unused__)): informs compiler to suppress 
  * warning about the unused argc
  * @argc: number of command line arguments passed to the function
  * @argv: array of string containing the commaind_line arguments 
  * passed to the program
  * Description: main takes command-line arguments, opens a file
  * reads the ELF header from the file, and then calls various
  * functions to process and print information about the ELF file
  * format,frees allocated memory and closes the file before
  * returning an exit status code to the operating system
  * Return: int on success and negative int on failure
  */
int main(int __attribute__((__unused__)) argc, char *argv[]) 
{
	Elf64_Ehdr *elf_header;
	int file_descriptor, bytes_read;

	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		dprintf(STDERR_FILENO, "Error: Failed to open file '%s'\n", argv[1]);
		exit(98);
	}

	elf_header = malloc(sizeof(Elf64_Ehdr));
	if (elf_header == NULL)
	{
		close(file_descriptor);
		dprintf(STDERR_FILENO, "Error: Failed to allocate memory for ELF header\n");
		exit(98);
	}

	bytes_read = read(file_descriptor, elf_header, sizeof(Elf64_Ehdr));
	if (bytes_read == -1)
	{
		free(elf_header);
		close(file_descriptor);
		dprintf(STDERR_FILENO, "Error: Error: Failed to read ELF header from file '%s'\n", argv[1]);
		exit(98);
	}

	validate_elf_identification(elf_header->e_ident);
	printf("ELF Header:\n");
	display_elf_magic(elf_header->e_ident);
	display_elf_class(elf_header->e_ident);
	display_elf_data(elf_header->e_ident);
	display_elf_version_info(elf_header->e_ident);
	display_elf_osabi(elf_header->e_ident);
	display_elf_abi_version(elf_header->e_ident);
	display_elf_file_type(elf_header->e_type, elf_header->e_ident);
	display_entry_point_address(elf_header->e_entry, elf_header->e_ident);

	free(elf_header);
	close(file_descriptor);
	return (0);
}
