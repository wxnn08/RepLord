set background=dark
syntax on
 
set showmatch		
set number		
set autoindent		
set smartindent
set shiftwidth=4
set softtabstop=4
set tabstop=4

au BufNewFile ~/*.cpp 0r ~/.base.cpp
