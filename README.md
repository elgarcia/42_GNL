# ䷉ 42_GNL ䷉
🤓 42 project about getting lines from a file. 🤓
********************************************
✅ **Objective** ✅
The main target of this function ( char *get_next_line(int fd) ) is basically get the file data line by line.
What we want to make sure on this project is to allocate enough memory (just the necessary) to work with, and then free the memory we dont.

📝 **Functions** 📝
* char	*first_read(int *b_read, int fd, char **buff, int *index);
	+ In this function what we do is allocate the memory for the static variable where we want to save the buffer data we read from the file using the read function from C library <unistd.h>.
	+ It returns the buffer content in case it's allocated correctely, if not it just return NULL pointer.

* int	read_buff(int *b_read, int fd, char **buff, char **line);
	+ In this function what we do is read again from the file in case there are more data to import.
	+ It just return a integer value (1 or 0) to check errors in the main function.

* char     *get_line(char **line, char **buff, int *check);
	+ In this function what we do is check the buffer data to see if there is a new line character available to return a string in the main function. If not it just append the buffer to a string previously allocated to prepare the data returned in the main function.
	+ It returns the string that contains the new line character, if not return a NULL pointer.
*	char    *get_next_line(int fd);
	+ This is the main function, where we use the other functions to extract the data from the file until we get a new line character or a null one.
	+ It return the line we get using the functions with the memory correctely allocated (it will be freed on the main). In case there is no option to read or wrong file descriptor it directely returns NULL pointer.

🧾  **Auxiliar Function** 🧾

See libft project to get info. -> [Elgarcia's libft](https://github.com/elgarcia/42_Libft[)