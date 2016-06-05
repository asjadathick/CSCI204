#include <iostream>
#include <regex>

using namespace std;

string removeMarkup(string input){
	string res = input;
	//string res = "<xmp>" + input + "</xmp>";
	//string res = "<b href='sss'>hello</b>";
	res = regex_replace(res, regex(" *\\<[^>]*\\> *"), "");
	//res = regex_replace(res, regex("(<[a-zA-Z]*>)|(<\/[a-zA-Z]*>)"), "");
	
	return res;
}

int main(){
	cout << removeMarkup("'<p>I''m using this slider i found:</p>&#xA;&#xA;<p><a href=\"http://dev7studios.com/lean-slider/\" rel=\"nofollow\">Lean Slider</a></p>&#xA;&#xA;<p>I want to know if there is any possibility to change it''s transition effect from FADE to SLIDE?&#xA;I have a basic knowledge in javascript/JQuery.&#xA;I tried to look for it but there is no mention to \"fade\" or \"slide\" in the code, so i don''t know where to begin.</p>&#xA;&#xA;<p>Thanks.</p>&#xA;'") << endl;
}