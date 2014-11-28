__author__ = 'duangao'

symbol_order_list=False
symbol_unorder_list=False
symbol_block_list=False
symbol_code_block=False

language=['python','c++']
import os
import re


def handle_token(i):

    if len(i)>5 and i[0]==i[1]==i[-1]==i[-2]=='*':      # deal with bold char
        i="<b>"+handle_token(i[2:-2])+"</b>"
    if len(i)>3 and i[0]==i[-1] and i[0]=='*':                       # deal with italic char
            i="<i>"+handle_token(i[1:-1])+"</i>"
    if len(i)>5 and i[0]==i[1]==i[-1]==i[-2]=='~':      # deal with delete line
            i="<S>"+handle_token(i[2:-2])+"</S>"
    if len(i)>7 and i[0]=="\\":                                    # deal with link
        pattern=re.compile(r'(\\\[)(.*)(\])(\()(.*)\)')
        a=pattern.match(i)
        if a:
            text,url=a.group(2,5)
            i="<a href=\"" +url+"\" target=\"_blank\">"+text+"</a>"
            print(i)
        else:
            i=i
    if len(i)>6 and i[0]=="[":
        pattern=re.compile(r'(\[)(.*)(\])(\[)(.*)(\])')
        a=pattern.match(i)
        if a:
            text,sub=a.group(2,5)
            i=text+"<sup>"+sub+"</sup>"
        else:
            i=i

    else :
        i=i
    return i

def token(string):

    if symbol_code_block==False or string=="```\n":
        result=string.split()
    else:

        return string
    str_result=" "

    if len(result)==0:
        return ""

    sym=handle_token(result.pop(0))

    for i in result:
        i=handle_token(i)
        str_result+=str(i)+" "


    result=list([sym,str_result])

    return result

def set_symbol(*args):
    for i in args:
        i=False

def close_list(result):
    global symbol_order_list

    result=""
    if symbol_order_list==True:
        result="</ol>"
    symbol_order_list=False
    return result



def parse(line):
    result=token(line)

    global  symbol_code_block
    global  symbol_block_list
    symbol=""
    content=""

    if len(result)==0:
        result=close_list(result)
        return result

    if symbol_code_block==False or result==['```',' ']:

        (symbol,content)=result


    subsymbol=symbol.replace('.',' . ').split()

    num=0

    if len(subsymbol)==2:
        (num,dot)=subsymbol
        global symbol_order_list
        symbol_order_list=True


    # header
    if symbol=='#':
        result=close_list(result)
        result+="<h1><font face=\"Consolas\">"+content+"</font></h1>"
    elif symbol=='##':
        result=close_list(result)
        result+="<h2>"+content+"</h2>"

    elif symbol=='###':
        result=close_list(result)
        result+="<h3>"+content+"</h3>"
    elif symbol=='####':
        result=close_list(result)
        result+="<h4>"+content+"</h4>"
    elif symbol=='#####':
        result=close_list(result)
        result+="<h5>"+content+"</h5>"
    elif symbol=='######':
        result=close_list(result)
        result+="<h6>"+content+"</h6>"

    # unorderd list
    elif symbol=="+" or symbol=="*" or symbol=='-' :
        result=close_list(result)
        result+="<ul><li>"+content+"</li></ul>"



    # quote
    elif symbol=='>':
        result=close_list(result)
        result+="<blockquote><p style=\"color:#8fbc8f\"><strong><i>"+ content+"</i></strong></p></blockquote></br>"

    elif symbol=="```":
        result=close_list(result)

        if symbol_block_list==False and symbol_code_block==False:
            symbol_block_list=True
            result+="<blockquote>"+content+"</br>"
        elif symbol_block_list ==True or symbol_code_block==True:
            symbol_block_list=False
            symbol_code_block=False
            result+="</blockquote>"

    elif symbol[0:3]=="```" and symbol[3:] in language:
        result=close_list(result)
        if symbol_code_block == False:
            symbol_code_block=True
            result+="<blockquote style=\"background-color:#ffebcd\"></br>"

    # ordered list
    elif symbol_order_list==True:
        if num=="1":
            result="<ol><li>"+content+"</li>"
        else:
            result="<li>"+content+"</li>"
            symbol_order_list=True


    # direct content
    else:
        content=result[0]+result[1]
        if symbol_code_block==False:
            result=close_list(result)
        # handle with horiral line
        count=0

        for i in content:
            if i=='-':
                count+=1
        if count==len(content)-1:
            result+="<hr>"
        #########################
        elif symbol_code_block==True:
            content=result
            result=""
            print(content)
            length_blank_char=0
            for i in content:
                if i==' ':
                    length_blank_char+=1
                    result+="&nbsp;"

            for item in content.split():
                if item=="def":
                    result+="<font color=\"red\"> "+item+"</font> "
                elif item[0:6] == "print(" and item[-1]==")":
                    result+="<font color=\"blue\"> "+ item +"</font> "
                else:
                    result+="<font color=\"black\">"+item+"</font>"
            result+="</br>"
        else:
            result+="<p>"+content+"</p>"

        #return result


    return result




def main(loc,name):
    file=open(loc,"r")
    result=open(name+".html","w")
    symbol_unorder_list=False
    symbol_order_list=False
    result.write("<style type=\"text/css\">div {display: block;font-family: Consolas}#wrapper { width: 100%;"
                 " height:100%; margin: 0; "
                 " padding: 0;}#left { float:left;  width: 10%;  height: 100%;  }#second {   float:left;   width: 80%;"
                 "   height: 100%;   }#right {float:left;  width: 10%;  height: 100%; "
                 "}</style><div id=\"wrapper\"> <div id=\"left\"></div><div id=\"second\">")
    for eachline in file:
        l=(str)(parse(eachline))
        result.write(l)
    result.write("</div><div id=\"right\"></div></div>")


#location=input()
location="example.md"
name,ext=os.path.splitext(location)
if ext=='.md':
    main(location,name)

