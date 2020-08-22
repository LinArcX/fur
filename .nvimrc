"-------------- Key-mapping(F2-F11 are free) ------------""
"Switch between .c/.h files
nnoremap <F2> :FSHere<CR>

function! FormatCurrentFile()
    silent execute "!clang-format -i ". " " . expand('%:p')
    :e
endfunction
au BufEnter,BufWrite *.c call FormatCurrentFile()
au BufEnter,BufWrite *.h call FormatCurrentFile()

function! FormatMakeFile()
    :set noet|retab!
endfunction
au BufWrite Makefile call FormatMakeFile()

"------------- vim-quickui settings  ------------------"
let s:update = "update | w |"
let s:make = "make; \n"
let s:clean = "make clean; \n"

call quickui#menu#clear('P&roject')
" mrautsc--pvfe--io--b
call quickui#menu#install('P&roject', [
            \ [ '&make', s:update.'call HTerminal(0.4, 300.0, "'. s:make .'")' ],
            \ [ '&run', s:update.'call FTerminal("clear; sample/build/nubo \n")' ],
            \ [ '&clean', s:update.'call HTerminal(0.4, 300.0, "'. s:clean .'")' ],
            \ [ "--", '' ],
            \ [ "l&ibc-help", 'call LibcSH()' ],
            \ [ "libc-help-under-curs&or", 'call LibcSHUC()' ],
            \ ], 5000)
