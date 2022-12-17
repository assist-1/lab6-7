std::string* read(std::istream& in, bool flag_file, std::string fromfile_name)
{
	static std::string data[5];
	if(flag_file)
	{
		if(!in)
		{
			std::cerr << "There`s no file named " << fromfile_name << " in directory with project" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	for(int i = 0; i < 5; i ++)
	{
		if(flag_file) if(in.eof()) 
		{
			std::cerr << "You have to enter 5 parametres in file: University, Sex, Year, Month, Day"<< std::endl;
			std::cerr << "Example: MIEM woman 2002 12 20";
			exit(EXIT_FAILURE);
		}
		in >> data[i];
	}


//чекает символы после дня рождения, если там неопознанный символ, то ругнется
//после перехода на некст строку заканчивает ввод
	char c = ' ';
	if(!flag_file)c = in.get();
	while(true)
	{
		if(flag_file){ if(in.eof()) break;}
		else if(c == '\n') break;
		if(c != ' ' && c != '\r' && c!= '\n')
		{
			std::cerr << "Oops, you entered excess symbol " << c << std::endl;
			std::cerr << "You have to enter 5 parametres in file: University, Sex, Year, Month, Day"<< std::endl;
			std::cerr << "Example: MIEM woman 2002 12 21" << std:: endl;
			exit(EXIT_FAILURE);
		}
		c = in.get();
	}
	
	return data;
}