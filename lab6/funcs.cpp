string* read(std::istream& in, bool flag_file, string fromfile_name)
{
	static string data[5];
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
	

	if(data[0] != "MIEM" && data[0] != "MGTUU")
	{
		std::cerr << "You can enter only MIEM or MGTUU university"<< std::endl;
		exit(EXIT_FAILURE);
	}
	if(data[1] != "woman" && data[1] != "man")
	{
		std::cerr << "You have to enter sex: man or woman. "<< data[1] <<" is no sex." << std::endl;
		exit(EXIT_FAILURE);
	}
	if(std::stoi(data[2]) < 1000 || std::stoi(data[2]) > 9999 )
	{
		std::cerr << "Really? Were you born in "<< data[1] << "?" << std::endl;
		exit(EXIT_FAILURE);
	}
	if(std::stoi(data[3]) < 1 || std::stoi(data[3]) > 12 )
	{
		std::cerr << "There's no number of month " << data[3] << std::endl;
		exit(EXIT_FAILURE);
	}
	if(std::stoi(data[3]) < 1 || std::stoi(data[3]) > 31 )
	{
		std::cerr << "There's no number of day " << data[3] << std::endl;
		exit(EXIT_FAILURE);
	}
	return data;
}