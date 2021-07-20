# Track package from Brazil's post service(Correios)

This C++ program was created to Web Scrap Brazilian post service (Correios) website. The objective is to pass a package track number as input and then parse the html source in order to get the information concerning the status of this package.

The file correios.cpp by itselt is not enough to complete this task. I relied on the terminal cmd curl, so it can handle the http request for us and then the c++ file handles the parsing and the result's output.

In conclusion to run we need to enter in terminal:

>curl http://www.linkcorreios.com.br/'enter_your_track_number' | ./correios.out 

Where correios.out is the executable file, compiled from correios.cpp.

I actually created a bash function in my terminal so I just need to enter: 

>correios 'object_track_number'

The alias looks like this:

>correios(){
  curl https://www.linkcorreios.com.br/"$1" -s | ./correios.out
}