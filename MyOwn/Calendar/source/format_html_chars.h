#ifndef FORMAT_HTML_CHARS
#define FORMAT_HTML_CHARS

#include <string>

void format_html_chars(std::string& html_string){
	std::string chars[48] = {"Á","á","À","à","Â","â","Ä","ä","Ã","ã","Ç","ç","É",
					         "é","È","è","Ê","ê","Ë","ë","Í","í","Ì","ì","Î","î",
					         "Ï","ï","Ñ","ñ","Ó","ó","Ò","ò","Ô","ô","Ö","ö","Õ",
					         "õ","Ú","ú","Ù","ù","Û","û","Ü","ü"};

	std::string formated_chars[48] = {"&Aacute;","&aacute;","&Agrave;","&agrave;",
								      "&Acirc;","&acirc;","&Auml;","&auml;","&Atilde;",
								      "&atilde;","&Ccedil;","&ccedil;","&Eacute;",
								      "&eacute;","&Egrave;","&egrave;","&Ecirc;",
								      "&ecirc;","&Euml;","&euml;","&Iacute;","&iacute;",
								      "&Igrave;","&igrave;","&Icirc;","&icirc;",
								      "&Iuml;","&iuml;","&Ntilde;","&ntilde;","&Oacute;",
								      "&oacute;","&Ograve;","&ograve;","&Ocirc;",
								      "&ocirc;","&Ouml;","&ouml;","&Otilde;","&otilde;",
								      "&Uacute;","&uacute;","&Ugrave;","&ugrave;",
								      "&Ucirc;","&ucirc;","&Uuml;","&uuml;"};

	for(int i=0;i<48;i++){
		int pos = html_string.find(chars[i]);
		while(pos != -1){
			html_string.replace(pos,2,formated_chars[i]);
			pos = html_string.find(chars[i]);
		}
	}
}

#endif