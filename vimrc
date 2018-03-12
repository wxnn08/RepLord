colorscheme ron
syntax on:
set number		
set showmatch		
set visualbell		
 
set autoindent		
set shiftwidth=4	
set softtabstop=4

nnoremap <C-J> <C-W><C-J>
nnoremap <C-K> <C-W><C-K>
nnoremap <C-L> <C-W><C-L>
nnoremap <C-H> <C-W><C-H>

au BufNewFile ~/*.cpp 0r ~/Documentos/prog/base.cpp
