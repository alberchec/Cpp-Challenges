# Track package from Brazil's post service(Correios)

## Current version

This C++ program was created to Web Scrap Brazilian post service (Correios) website.

The previous version needed a bash function to work, because in this application I use the terminal cmd curl. But now I implemented the curl cmd inside the C++ file, so the bash function is not required. I only use it to be able to call the program as it was a cmd in terminal.

---

### About the program

This program is used to get Brazilian post service(Correios) packages status by Web scraping the html file returned when requested by curl cmd. I used the system function from cstdlib to be able to implement curl inside C++.

Packages tracking numbers are stored in a file named track_numbers.txt. The program search for this numbers inside the file and then requests the package status on the Correios web page.

Tracking numbers can be added to track_numbers.txt file via arguments passed to the executable. They can also be removed and listed.

---

### How to execute it

First inside correios.cpp is necessary to define two file locations. 

- The first temp_file is where the html content is going to be temporary stored.

- The second is track_numbers_file, location where your tracking numbers are going to be stored.

After compiling correios.cpp and obtaining correios.out, you can run the executable in five manners.

- Add tracking numbers

> ./correios.out "track_number" "Package description"

- List tracking numbers stored

> ./correios.out -l

- Delete tracking number

> ./correios.out -d "number from list"

- Delete all tracking numbers stored

> ./correios.out --d-all

- Get packages status

> ./correios.out

---

### Bash function

In order to facilitate the usage of this application I created a bash function, so instead of entering ./correios.out, I just need to enter correios.

See how I did it:

> correios(){ \
  ~/"replace_with_your_path"/correios.out "$1" "$2" \
  rm -f ~/"replace_with_your_path"/track.html \
}

---

## Previous version

Now available at commit 1317ef5748f8144572781f4faaeb1ffd308e19a1

This C++ program was created to Web Scrap Brazilian post service (Correios) website. The objective is to pass a package track number as input and then parse the html source in order to get the information concerning the status of this package.

The file correios.cpp by itselt is not enough to complete this task. I relied on the terminal cmd curl, so it can handle the http request for us and then the C++ file handles the parsing and the result's output.

In conclusion to run we need to enter in terminal:

>curl http://www.linkcorreios.com.br/'enter_your_track_number' | ./correios.out 

Where correios.out is the executable file, compiled from correios.cpp.

I actually created a bash function in my terminal so I just need to enter: 

>correios 'package_track_number'

The bash function looks like this:

>correios(){ \
  curl https://www.linkcorreios.com.br/"$1" -s | ./correios.out \
}