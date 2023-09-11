#ifndef DOG_H
#define DOG_H
/**
  * struct dog - dog's struct containaining it's basic information
  * @name: dog's name
  * @age: dog's age
  * @owner: dog's owner
  * Description: structure of dog with memebers  explaning it's basic
  * member informations with different variables
  */
struct dog
{
	char *name;
	float age;
	char *owner;

};

/**
 * dog_t - typedef for dod's structure
 */
typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

#endif
