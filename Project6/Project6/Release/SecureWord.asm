﻿; Listing generated by Microsoft (R) Optimizing Compiler Version 19.16.27032.1 

	TITLE	e:\csgo\project6\project6\secureword.cpp
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB OLDNAMES

PUBLIC	??_C@_0BG@HGEDEDEC@invalid?5stoi?5argument@	; `string'
PUBLIC	??_C@_0BL@MFFNMGGC@stoi?5argument?5out?5of?5range@ ; `string'
PUBLIC	??_C@_0BA@JFNIOLAK@string?5too?5long@		; `string'
EXTRN	__imp___invalid_parameter_noinfo_noreturn:PROC
EXTRN	__imp____std_terminate:PROC
EXTRN	__imp__strtol:PROC
EXTRN	__imp___errno:PROC
EXTRN	??3@YAXPAXI@Z:PROC				; operator delete
EXTRN	__imp_?_Xlength_error@std@@YAXPBD@Z:PROC
EXTRN	__imp_?_Xout_of_range@std@@YAXPBD@Z:PROC
EXTRN	__imp_?_Xinvalid_argument@std@@YAXPBD@Z:PROC
EXTRN	??2@YAPAXI@Z:PROC				; operator new
EXTRN	@__security_check_cookie@4:PROC
EXTRN	__imp____CxxFrameHandler3:PROC
;	COMDAT ??_C@_0BA@JFNIOLAK@string?5too?5long@
CONST	SEGMENT
??_C@_0BA@JFNIOLAK@string?5too?5long@ DB 'string too long', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BL@MFFNMGGC@stoi?5argument?5out?5of?5range@
CONST	SEGMENT
??_C@_0BL@MFFNMGGC@stoi?5argument?5out?5of?5range@ DB 'stoi argument out '
	DB	'of range', 00H				; `string'
CONST	ENDS
;	COMDAT ??_C@_0BG@HGEDEDEC@invalid?5stoi?5argument@
CONST	SEGMENT
??_C@_0BG@HGEDEDEC@invalid?5stoi?5argument@ DB 'invalid stoi argument', 00H ; `string'
CONST	ENDS
PUBLIC	??$_Allocate_manually_vector_aligned@U_Default_allocate_traits@std@@@std@@YAPAXI@Z ; std::_Allocate_manually_vector_aligned<std::_Default_allocate_traits>
PUBLIC	??$forward@ABQAD@std@@YAABQADABQAD@Z		; std::forward<char * const &>
PUBLIC	??$_Pocca@V?$allocator@D@std@@@std@@YAXAAV?$allocator@D@0@ABV10@U?$integral_constant@_N$0A@@0@@Z ; std::_Pocca<std::allocator<char> >
PUBLIC	??$?0V?$allocator@D@std@@$$V@?$_Compressed_pair@V?$allocator@D@std@@V?$_String_val@U?$_Simple_types@D@std@@@2@$00@std@@QAE@U_One_then_variadic_args_t@1@$$QAV?$allocator@D@1@@Z ; std::_Compressed_pair<std::allocator<char>,std::_String_val<std::_Simple_types<char> >,1>::_Compressed_pair<std::allocator<char>,std::_String_val<std::_Simple_types<char> >,1><std::allocator<char> >
PUBLIC	??$forward@V?$allocator@D@std@@@std@@YA$$QAV?$allocator@D@0@AAV10@@Z ; std::forward<std::allocator<char> >
PUBLIC	??0_Bxty@?$_String_val@U?$_Simple_types@D@std@@@std@@QAE@XZ ; std::_String_val<std::_Simple_types<char> >::_Bxty::_Bxty
PUBLIC	??0?$allocator@D@std@@QAE@XZ			; std::allocator<char>::allocator<char>
PUBLIC	?_Calculate_growth@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QBEII@Z ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::_Calculate_growth
PUBLIC	?_Xlen@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@SAXXZ ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::_Xlen
PUBLIC	??0?$_String_val@U?$_Simple_types@D@std@@@std@@QAE@XZ ; std::_String_val<std::_Simple_types<char> >::_String_val<std::_Simple_types<char> >
PUBLIC	??$_Deallocate@$07$0A@@std@@YAXPAXI@Z		; std::_Deallocate<8,0>
PUBLIC	??$_Allocate@$07U_Default_allocate_traits@std@@$0A@@std@@YAPAXI@Z ; std::_Allocate<8,std::_Default_allocate_traits,0>
PUBLIC	??$addressof@V?$_String_val@U?$_Simple_types@D@std@@@std@@@std@@YAPAV?$_String_val@U?$_Simple_types@D@std@@@0@AAV10@@Z ; std::addressof<std::_String_val<std::_Simple_types<char> > >
PUBLIC	??$construct@PADABQAD@?$_Default_allocator_traits@V?$allocator@D@std@@@std@@SAXAAV?$allocator@D@1@QAPADABQAD@Z ; std::_Default_allocator_traits<std::allocator<char> >::construct<char *,char * const &>
PUBLIC	??$_Reallocate_for@V<lambda_9366063389c5f42a00a5088cf24e69de>@@PBD@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QAEAAV01@IV<lambda_9366063389c5f42a00a5088cf24e69de>@@PBD@Z ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::_Reallocate_for<<lambda_9366063389c5f42a00a5088cf24e69de>,char const *>
PUBLIC	??$destroy@PAD@?$_Default_allocator_traits@V?$allocator@D@std@@@std@@SAXAAV?$allocator@D@1@QAPAD@Z ; std::_Default_allocator_traits<std::allocator<char> >::destroy<char *>
PUBLIC	??$addressof@PAD@std@@YAPAPADAAPAD@Z		; std::addressof<char *>
PUBLIC	??$?0$$V@?$_Compressed_pair@V?$allocator@D@std@@V?$_String_val@U?$_Simple_types@D@std@@@2@$00@std@@QAE@U_Zero_then_variadic_args_t@1@@Z ; std::_Compressed_pair<std::allocator<char>,std::_String_val<std::_Simple_types<char> >,1>::_Compressed_pair<std::allocator<char>,std::_String_val<std::_Simple_types<char> >,1><>
PUBLIC	??$_Pocca@V?$allocator@D@std@@@std@@YAXAAV?$allocator@D@0@ABV10@@Z ; std::_Pocca<std::allocator<char> >
PUBLIC	??$move@AAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@YA$$QAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@AAV10@@Z ; std::move<std::basic_string<char,std::char_traits<char>,std::allocator<char> > &>
PUBLIC	??$?0V?$allocator@D@std@@X@?$_String_alloc@U?$_String_base_types@DV?$allocator@D@std@@@std@@@std@@QAE@$$QAV?$allocator@D@1@@Z ; std::_String_alloc<std::_String_base_types<char,std::allocator<char> > >::_String_alloc<std::_String_base_types<char,std::allocator<char> > ><std::allocator<char>,void>
PUBLIC	??$move@AAV?$allocator@D@std@@@std@@YA$$QAV?$allocator@D@0@AAV10@@Z ; std::move<std::allocator<char> &>
PUBLIC	??$addressof@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@YAPBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@ABV10@@Z ; std::addressof<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const >
PUBLIC	??$_Unfancy@D@std@@YAPADPAD@Z			; std::_Unfancy<char>
PUBLIC	??$_Min_value@I@std@@YAABIABI0@Z		; std::_Min_value<unsigned int>
PUBLIC	?max_size@?$_Default_allocator_traits@V?$allocator@D@std@@@std@@SAIABV?$allocator@D@2@@Z ; std::_Default_allocator_traits<std::allocator<char> >::max_size
PUBLIC	?_Get_first@?$_Compressed_pair@V?$allocator@D@std@@V?$_String_val@U?$_Simple_types@D@std@@@2@$00@std@@QAEAAV?$allocator@D@2@XZ ; std::_Compressed_pair<std::allocator<char>,std::_String_val<std::_Simple_types<char> >,1>::_Get_first
PUBLIC	?_Get_first@?$_Compressed_pair@V?$allocator@D@std@@V?$_String_val@U?$_Simple_types@D@std@@@2@$00@std@@QBEABV?$allocator@D@2@XZ ; std::_Compressed_pair<std::allocator<char>,std::_String_val<std::_Simple_types<char> >,1>::_Get_first
PUBLIC	?_Get_second@?$_Compressed_pair@V?$allocator@D@std@@V?$_String_val@U?$_Simple_types@D@std@@@2@$00@std@@QAEAAV?$_String_val@U?$_Simple_types@D@std@@@2@XZ ; std::_Compressed_pair<std::allocator<char>,std::_String_val<std::_Simple_types<char> >,1>::_Get_second
PUBLIC	?_Get_second@?$_Compressed_pair@V?$allocator@D@std@@V?$_String_val@U?$_Simple_types@D@std@@@2@$00@std@@QBEABV?$_String_val@U?$_Simple_types@D@std@@@2@XZ ; std::_Compressed_pair<std::allocator<char>,std::_String_val<std::_Simple_types<char> >,1>::_Get_second
PUBLIC	?deallocate@?$allocator@D@std@@QAEXQADI@Z	; std::allocator<char>::deallocate
PUBLIC	?allocate@?$allocator@D@std@@QAEPADI@Z		; std::allocator<char>::allocate
PUBLIC	?_Assign_rv_contents_with_alloc_always_equal@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QAEX$$QAV12@U?$integral_constant@_N$00@2@@Z ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::_Assign_rv_contents_with_alloc_always_equal
PUBLIC	?_Construct_lv_contents@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QAEXABV12@@Z ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::_Construct_lv_contents
PUBLIC	??R<lambda_9366063389c5f42a00a5088cf24e69de>@@QBEXQADIQBD@Z ; <lambda_9366063389c5f42a00a5088cf24e69de>::operator()
PUBLIC	?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QAEAAV12@QBDI@Z ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::assign
PUBLIC	??$_Max_value@I@std@@YAABIABI0@Z		; std::_Max_value<unsigned int>
PUBLIC	?max_size@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QBEIXZ ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::max_size
PUBLIC	?_Tidy_init@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QAEXXZ ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::_Tidy_init
PUBLIC	?_Tidy_deallocate@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QAEXXZ ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::_Tidy_deallocate
PUBLIC	??0?$_String_alloc@U?$_String_base_types@DV?$allocator@D@std@@@std@@@std@@QAE@XZ ; std::_String_alloc<std::_String_base_types<char,std::allocator<char> > >::_String_alloc<std::_String_base_types<char,std::allocator<char> > >
PUBLIC	?_Copy_alloc@?$_String_alloc@U?$_String_base_types@DV?$allocator@D@std@@@std@@@std@@QAEXABV?$allocator@D@2@@Z ; std::_String_alloc<std::_String_base_types<char,std::allocator<char> > >::_Copy_alloc
PUBLIC	?_Orphan_all@?$_String_alloc@U?$_String_base_types@DV?$allocator@D@std@@@std@@@std@@QAEXXZ ; std::_String_alloc<std::_String_base_types<char,std::allocator<char> > >::_Orphan_all
PUBLIC	?_Getal@?$_String_alloc@U?$_String_base_types@DV?$allocator@D@std@@@std@@@std@@QAEAAV?$allocator@D@2@XZ ; std::_String_alloc<std::_String_base_types<char,std::allocator<char> > >::_Getal
PUBLIC	?_Getal@?$_String_alloc@U?$_String_base_types@DV?$allocator@D@std@@@std@@@std@@QBEABV?$allocator@D@2@XZ ; std::_String_alloc<std::_String_base_types<char,std::allocator<char> > >::_Getal
PUBLIC	?_Get_data@?$_String_alloc@U?$_String_base_types@DV?$allocator@D@std@@@std@@@std@@QAEAAV?$_String_val@U?$_Simple_types@D@std@@@2@XZ ; std::_String_alloc<std::_String_base_types<char,std::allocator<char> > >::_Get_data
PUBLIC	?_Get_data@?$_String_alloc@U?$_String_base_types@DV?$allocator@D@std@@@std@@@std@@QBEABV?$_String_val@U?$_Simple_types@D@std@@@2@XZ ; std::_String_alloc<std::_String_base_types<char,std::allocator<char> > >::_Get_data
PUBLIC	?select_on_container_copy_construction@?$_Default_allocator_traits@V?$allocator@D@std@@@std@@SA?AV?$allocator@D@2@ABV32@@Z ; std::_Default_allocator_traits<std::allocator<char> >::select_on_container_copy_construction
PUBLIC	?_Myptr@?$_String_val@U?$_Simple_types@D@std@@@std@@QAEPADXZ ; std::_String_val<std::_Simple_types<char> >::_Myptr
PUBLIC	?_Myptr@?$_String_val@U?$_Simple_types@D@std@@@std@@QBEPBDXZ ; std::_String_val<std::_Simple_types<char> >::_Myptr
PUBLIC	?_Large_string_engaged@?$_String_val@U?$_Simple_types@D@std@@@std@@QBE_NXZ ; std::_String_val<std::_Simple_types<char> >::_Large_string_engaged
PUBLIC	??1_Bxty@?$_String_val@U?$_Simple_types@D@std@@@std@@QAE@XZ ; std::_String_val<std::_Simple_types<char> >::_Bxty::~_Bxty
PUBLIC	??1?$_String_val@U?$_Simple_types@D@std@@@std@@QAE@XZ ; std::_String_val<std::_Simple_types<char> >::~_String_val<std::_Simple_types<char> >
PUBLIC	??1?$_Compressed_pair@V?$allocator@D@std@@V?$_String_val@U?$_Simple_types@D@std@@@2@$00@std@@QAE@XZ ; std::_Compressed_pair<std::allocator<char>,std::_String_val<std::_Simple_types<char> >,1>::~_Compressed_pair<std::allocator<char>,std::_String_val<std::_Simple_types<char> >,1>
PUBLIC	??1?$_String_alloc@U?$_String_base_types@DV?$allocator@D@std@@@std@@@std@@QAE@XZ ; std::_String_alloc<std::_String_base_types<char,std::allocator<char> > >::~_String_alloc<std::_String_base_types<char,std::allocator<char> > >
PUBLIC	??0?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QAE@ABV01@@Z ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::basic_string<char,std::char_traits<char>,std::allocator<char> >
PUBLIC	??0?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QAE@XZ ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::basic_string<char,std::char_traits<char>,std::allocator<char> >
PUBLIC	??0?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QAE@$$QAV01@@Z ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::basic_string<char,std::char_traits<char>,std::allocator<char> >
PUBLIC	??1?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QAE@XZ ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string<char,std::char_traits<char>,std::allocator<char> >
PUBLIC	??4?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QAEAAV01@ABV01@@Z ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::operator=
PUBLIC	??A?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QAEAADI@Z ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::operator[]
PUBLIC	?c_str@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QBEPBDXZ ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::c_str
PUBLIC	?size@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QBEIXZ ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::size
PUBLIC	??1SecureWord@@QAE@XZ				; SecureWord::~SecureWord
PUBLIC	?getword@SecureWord@@QAE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ ; SecureWord::getword
PUBLIC	?code@SecureWord@@QAEXXZ			; SecureWord::code
PUBLIC	?decode@SecureWord@@QAE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ ; SecureWord::decode
PUBLIC	??0SecureWord@@QAE@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@00@Z ; SecureWord::SecureWord
PUBLIC	?stoi@std@@YAHABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAIH@Z ; std::stoi
PUBLIC	?_Adjust_manually_vector_aligned@std@@YAXAAPAXAAI@Z ; std::_Adjust_manually_vector_aligned
PUBLIC	?_Allocate@_Default_allocate_traits@std@@SAPAXI@Z ; std::_Default_allocate_traits::_Allocate
PUBLIC	??$_Get_size_of_n@$00@std@@YAII@Z		; std::_Get_size_of_n<1>
PUBLIC	?_Orphan_all@_Container_base0@std@@QAEXXZ	; std::_Container_base0::_Orphan_all
PUBLIC	?assign@?$char_traits@D@std@@SAXAADABD@Z	; std::char_traits<char>::assign
PUBLIC	?move@?$char_traits@D@std@@SAPADQADQBDI@Z	; std::char_traits<char>::move
PUBLIC	?copy@?$char_traits@D@std@@SAPADQADQBDI@Z	; std::char_traits<char>::copy
PUBLIC	?max@?$numeric_limits@H@std@@SAHXZ		; std::numeric_limits<int>::max
PUBLIC	??2@YAPAXIPAX@Z					; operator new
EXTRN	__CxxThrowException@8:PROC
EXTRN	___CxxFrameHandler3:PROC
EXTRN	___std_terminate:PROC
EXTRN	_memcpy:PROC
EXTRN	_memmove:PROC
EXTRN	_memset:PROC
EXTRN	___security_cookie:DWORD
;	COMDAT xdata$x
xdata$x	SEGMENT
__ehfuncinfo$??0SecureWord@@QAE@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@00@Z DD 019930522H
	DD	04H
	DD	FLAT:__unwindtable$??0SecureWord@@QAE@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@00@Z
	DD	2 DUP(00H)
	DD	2 DUP(00H)
	DD	00H
	DD	01H
__unwindtable$??0SecureWord@@QAE@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@00@Z DD 0ffffffffH
	DD	FLAT:__unwindfunclet$??0SecureWord@@QAE@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@00@Z$0
	DD	00H
	DD	FLAT:__unwindfunclet$??0SecureWord@@QAE@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@00@Z$1
	DD	01H
	DD	FLAT:__unwindfunclet$??0SecureWord@@QAE@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@00@Z$2
	DD	02H
	DD	FLAT:__unwindfunclet$??0SecureWord@@QAE@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@00@Z$3
xdata$x	ENDS
; Function compile flags: /Ogtp
;	COMDAT ??0SecureWord@@QAE@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@00@Z
_TEXT	SEGMENT
_this$GSCopy$ = -24					; size = 4
__Eptr$54 = -20						; size = 4
__Eptr$55 = -20						; size = 4
_this$ = -20						; size = 4
__$ArrayPad$ = -16					; size = 4
__$EHRec$ = -12						; size = 12
_str$ = 8						; size = 24
_encrypt$ = 32						; size = 24
_keyWord$ = 56						; size = 24
??0SecureWord@@QAE@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@00@Z PROC ; SecureWord::SecureWord, COMDAT
; _this$ = ecx
; File e:\csgo\project6\project6\secureword.cpp
; Line 4
	push	ebp
	mov	ebp, esp
	push	-1
	push	__ehhandler$??0SecureWord@@QAE@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@00@Z
	mov	eax, DWORD PTR fs:0
	push	eax
	sub	esp, 12					; 0000000cH
	mov	eax, DWORD PTR ___security_cookie
	xor	eax, ebp
	mov	DWORD PTR __$ArrayPad$[ebp], eax
	push	ebx
	push	esi
	push	edi
	push	eax
	lea	eax, DWORD PTR __$EHRec$[ebp]
	mov	DWORD PTR fs:0, eax
	mov	edi, ecx
	mov	DWORD PTR _this$[ebp], edi
	mov	DWORD PTR _this$GSCopy$[ebp], edi
	mov	DWORD PTR __$EHRec$[ebp+8], 0
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstring
; Line 3976
	mov	DWORD PTR [edi+16], 0
; Line 3977
	mov	DWORD PTR [edi+20], 15			; 0000000fH
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\iosfwd
; Line 506
	mov	BYTE PTR [edi], 0
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstring
; Line 2467
	lea	eax, DWORD PTR _str$[ebp]
; File e:\csgo\project6\project6\secureword.cpp
; Line 4
	mov	BYTE PTR __$EHRec$[ebp+8], 3
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstring
; Line 2467
	cmp	edi, eax
	je	SHORT $LN30@SecureWord
; Line 1825
	cmp	DWORD PTR _str$[ebp+20], 16		; 00000010H
; Line 2481
	push	DWORD PTR _str$[ebp+16]
; Line 1815
	cmovae	eax, DWORD PTR _str$[ebp]
; Line 2481
	push	eax
	call	?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QAEAAV12@QBDI@Z ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::assign
$LN30@SecureWord:
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\string
; Line 182
	call	DWORD PTR __imp___errno
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstring
; Line 1825
	cmp	DWORD PTR _encrypt$[ebp+20], 16		; 00000010H
; Line 1814
	lea	esi, DWORD PTR _encrypt$[ebp]
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\string
; Line 182
	mov	ebx, eax
; Line 186
	lea	eax, DWORD PTR __Eptr$55[ebp]
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstring
; Line 1815
	cmovae	esi, DWORD PTR _encrypt$[ebp]
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\string
; Line 186
	push	10					; 0000000aH
	push	eax
	push	esi
	mov	DWORD PTR [ebx], 0
	call	DWORD PTR __imp__strtol
	add	esp, 12					; 0000000cH
; Line 188
	cmp	esi, DWORD PTR __Eptr$55[ebp]
	jne	SHORT $LN61@SecureWord
; Line 189
	push	OFFSET ??_C@_0BG@HGEDEDEC@invalid?5stoi?5argument@
	call	DWORD PTR __imp_?_Xinvalid_argument@std@@YAXPBD@Z
$LN61@SecureWord:
; Line 190
	cmp	DWORD PTR [ebx], 34			; 00000022H
	je	$LN83@SecureWord
; File e:\csgo\project6\project6\secureword.cpp
; Line 7
	cmp	eax, 1
	jne	SHORT $LN2@SecureWord
; Line 9
	mov	BYTE PTR [edi+24], al
; Line 11
	jmp	SHORT $LN3@SecureWord
$LN2@SecureWord:
; Line 13
	mov	BYTE PTR [edi+24], 0
$LN3@SecureWord:
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\string
; Line 182
	call	DWORD PTR __imp___errno
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstring
; Line 1825
	cmp	DWORD PTR _keyWord$[ebp+20], 16		; 00000010H
; Line 1814
	lea	esi, DWORD PTR _keyWord$[ebp]
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\string
; Line 182
	mov	ebx, eax
; Line 186
	lea	eax, DWORD PTR __Eptr$54[ebp]
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstring
; Line 1815
	cmovae	esi, DWORD PTR _keyWord$[ebp]
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\string
; Line 186
	push	10					; 0000000aH
	push	eax
	push	esi
	mov	DWORD PTR [ebx], 0
	call	DWORD PTR __imp__strtol
	add	esp, 12					; 0000000cH
; Line 188
	cmp	esi, DWORD PTR __Eptr$54[ebp]
	jne	SHORT $LN81@SecureWord
; Line 189
	push	OFFSET ??_C@_0BG@HGEDEDEC@invalid?5stoi?5argument@
	call	DWORD PTR __imp_?_Xinvalid_argument@std@@YAXPBD@Z
$LN81@SecureWord:
; Line 190
	cmp	DWORD PTR [ebx], 34			; 00000022H
	je	$LN83@SecureWord
; File e:\csgo\project6\project6\secureword.cpp
; Line 16
	cmp	BYTE PTR [edi+24], 0
	mov	DWORD PTR [edi+28], eax
; Line 19
	jne	$LN4@SecureWord
; Line 61
	xor	esi, esi
	cmp	DWORD PTR [edi+16], esi
	jbe	$LN101@SecureWord
$LL102@SecureWord:
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstring
; Line 1825
	mov	ebx, DWORD PTR [edi+20]
; Line 1803
	mov	eax, edi
; Line 1825
	cmp	ebx, 16					; 00000010H
; Line 1804
	jb	SHORT $LN403@SecureWord
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstddef
; Line 346
	mov	eax, DWORD PTR [edi]
$LN403@SecureWord:
; File e:\csgo\project6\project6\secureword.cpp
; Line 63
	cmp	BYTE PTR [eax+esi], 122			; 0000007aH
	jg	SHORT $LN103@SecureWord
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstring
; Line 1803
	mov	eax, edi
; Line 1825
	cmp	ebx, 16					; 00000010H
; Line 1804
	jb	SHORT $LN400@SecureWord
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstddef
; Line 346
	mov	eax, DWORD PTR [edi]
$LN400@SecureWord:
; File e:\csgo\project6\project6\secureword.cpp
; Line 63
	cmp	BYTE PTR [eax+esi], 97			; 00000061H
	jl	SHORT $LN103@SecureWord
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstring
; Line 1803
	mov	eax, edi
; Line 1825
	cmp	ebx, 16					; 00000010H
; Line 1804
	jb	SHORT $LN404@SecureWord
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstddef
; Line 346
	mov	eax, DWORD PTR [edi]
$LN404@SecureWord:
; File e:\csgo\project6\project6\secureword.cpp
; Line 66
	movsx	ecx, BYTE PTR [eax+esi]
	mov	eax, DWORD PTR [edi+28]
	add	eax, -97				; ffffff9fH
	add	eax, ecx
	mov	ecx, 26					; 0000001aH
	cdq
	idiv	ecx
	add	dl, 97					; 00000061H
	jmp	SHORT $LN413@SecureWord
$LN103@SecureWord:
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstring
; Line 1803
	mov	eax, edi
; Line 1825
	cmp	ebx, 16					; 00000010H
; Line 1804
	jb	SHORT $LN401@SecureWord
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstddef
; Line 346
	mov	eax, DWORD PTR [edi]
$LN401@SecureWord:
; File e:\csgo\project6\project6\secureword.cpp
; Line 69
	cmp	BYTE PTR [eax+esi], 90			; 0000005aH
	jg	SHORT $LN100@SecureWord
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstring
; Line 1803
	mov	eax, edi
; Line 1825
	cmp	ebx, 16					; 00000010H
; Line 1804
	jb	SHORT $LN402@SecureWord
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstddef
; Line 346
	mov	eax, DWORD PTR [edi]
$LN402@SecureWord:
; File e:\csgo\project6\project6\secureword.cpp
; Line 69
	cmp	BYTE PTR [eax+esi], 65			; 00000041H
	jl	SHORT $LN100@SecureWord
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstring
; Line 1803
	mov	eax, edi
; Line 1825
	cmp	ebx, 16					; 00000010H
; Line 1804
	jb	SHORT $LN405@SecureWord
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstddef
; Line 346
	mov	eax, DWORD PTR [edi]
$LN405@SecureWord:
; File e:\csgo\project6\project6\secureword.cpp
; Line 72
	movsx	ecx, BYTE PTR [eax+esi]
	mov	eax, DWORD PTR [edi+28]
	add	eax, -65				; ffffffbfH
	add	eax, ecx
	mov	ecx, 26					; 0000001aH
	cdq
	idiv	ecx
	add	dl, 65					; 00000041H
$LN413@SecureWord:
; Line 61
	mov	eax, edi
	cmp	ebx, 16					; 00000010H
	jb	SHORT $LN211@SecureWord
	mov	eax, DWORD PTR [edi]
$LN211@SecureWord:
	mov	BYTE PTR [eax+esi], dl
$LN100@SecureWord:
	inc	esi
	cmp	esi, DWORD PTR [edi+16]
	jb	$LL102@SecureWord
$LN101@SecureWord:
; Line 76
	mov	BYTE PTR [edi+24], 1
$LN4@SecureWord:
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstring
; Line 1825
	mov	edx, DWORD PTR _str$[ebp+20]
	cmp	edx, 16					; 00000010H
; Line 3987
	jb	SHORT $LN260@SecureWord
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xmemory0
; Line 992
	mov	ecx, DWORD PTR _str$[ebp]
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstring
; Line 3992
	inc	edx
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xmemory0
; Line 992
	mov	eax, ecx
; Line 201
	cmp	edx, 4096				; 00001000H
	jb	SHORT $LN259@SecureWord
; Line 118
	mov	ecx, DWORD PTR [ecx-4]
	add	edx, 35					; 00000023H
	sub	eax, ecx
; Line 132
	add	eax, -4					; fffffffcH
	cmp	eax, 31					; 0000001fH
	jbe	SHORT $LN259@SecureWord
	call	DWORD PTR __imp___invalid_parameter_noinfo_noreturn
$LN259@SecureWord:
; Line 207
	push	edx
	push	ecx
	call	??3@YAXPAXI@Z				; operator delete
	add	esp, 8
$LN260@SecureWord:
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstring
; Line 1825
	mov	edx, DWORD PTR _encrypt$[ebp+20]
; Line 3995
	mov	DWORD PTR _str$[ebp+16], 0
; Line 3996
	mov	DWORD PTR _str$[ebp+20], 15		; 0000000fH
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\iosfwd
; Line 506
	mov	BYTE PTR _str$[ebp], 0
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstring
; Line 1825
	cmp	edx, 16					; 00000010H
; Line 3987
	jb	SHORT $LN320@SecureWord
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xmemory0
; Line 992
	mov	ecx, DWORD PTR _encrypt$[ebp]
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstring
; Line 3992
	inc	edx
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xmemory0
; Line 992
	mov	eax, ecx
; Line 201
	cmp	edx, 4096				; 00001000H
	jb	SHORT $LN319@SecureWord
; Line 118
	mov	ecx, DWORD PTR [ecx-4]
	add	edx, 35					; 00000023H
	sub	eax, ecx
; Line 132
	add	eax, -4					; fffffffcH
	cmp	eax, 31					; 0000001fH
	jbe	SHORT $LN319@SecureWord
	call	DWORD PTR __imp___invalid_parameter_noinfo_noreturn
$LN319@SecureWord:
; Line 207
	push	edx
	push	ecx
	call	??3@YAXPAXI@Z				; operator delete
	add	esp, 8
$LN320@SecureWord:
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstring
; Line 1825
	mov	edx, DWORD PTR _keyWord$[ebp+20]
; Line 3995
	mov	DWORD PTR _encrypt$[ebp+16], 0
; Line 3996
	mov	DWORD PTR _encrypt$[ebp+20], 15		; 0000000fH
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\iosfwd
; Line 506
	mov	BYTE PTR _encrypt$[ebp], 0
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstring
; Line 1825
	cmp	edx, 16					; 00000010H
; Line 3987
	jb	SHORT $LN380@SecureWord
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xmemory0
; Line 992
	mov	ecx, DWORD PTR _keyWord$[ebp]
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstring
; Line 3992
	inc	edx
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xmemory0
; Line 992
	mov	eax, ecx
; Line 201
	cmp	edx, 4096				; 00001000H
	jb	SHORT $LN379@SecureWord
; Line 118
	mov	ecx, DWORD PTR [ecx-4]
	add	edx, 35					; 00000023H
	sub	eax, ecx
; Line 132
	add	eax, -4					; fffffffcH
	cmp	eax, 31					; 0000001fH
	jbe	SHORT $LN379@SecureWord
	call	DWORD PTR __imp___invalid_parameter_noinfo_noreturn
$LN379@SecureWord:
; Line 207
	push	edx
	push	ecx
	call	??3@YAXPAXI@Z				; operator delete
	add	esp, 8
$LN380@SecureWord:
; File e:\csgo\project6\project6\secureword.cpp
; Line 25
	mov	eax, edi
	mov	ecx, DWORD PTR __$EHRec$[ebp]
	mov	DWORD PTR fs:0, ecx
	pop	ecx
	pop	edi
	pop	esi
	pop	ebx
	mov	ecx, DWORD PTR __$ArrayPad$[ebp]
	xor	ecx, ebp
	call	@__security_check_cookie@4
	mov	esp, ebp
	pop	ebp
	ret	72					; 00000048H
$LN83@SecureWord:
	push	OFFSET ??_C@_0BL@MFFNMGGC@stoi?5argument?5out?5of?5range@
	call	DWORD PTR __imp_?_Xout_of_range@std@@YAXPBD@Z
$LN410@SecureWord:
	int	3
_TEXT	ENDS
;	COMDAT text$x
text$x	SEGMENT
__unwindfunclet$??0SecureWord@@QAE@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@00@Z$0:
	lea	ecx, DWORD PTR _keyWord$[ebp]
	jmp	??1?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QAE@XZ ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string<char,std::char_traits<char>,std::allocator<char> >
__unwindfunclet$??0SecureWord@@QAE@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@00@Z$1:
	lea	ecx, DWORD PTR _encrypt$[ebp]
	jmp	??1?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QAE@XZ ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string<char,std::char_traits<char>,std::allocator<char> >
__unwindfunclet$??0SecureWord@@QAE@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@00@Z$2:
	lea	ecx, DWORD PTR _str$[ebp]
	jmp	??1?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QAE@XZ ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string<char,std::char_traits<char>,std::allocator<char> >
__unwindfunclet$??0SecureWord@@QAE@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@00@Z$3:
	mov	ecx, DWORD PTR _this$GSCopy$[ebp]
	jmp	??1?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QAE@XZ ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string<char,std::char_traits<char>,std::allocator<char> >
__ehhandler$??0SecureWord@@QAE@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@00@Z:
	mov	edx, DWORD PTR [esp+8]
	lea	eax, DWORD PTR [edx+12]
	mov	ecx, DWORD PTR [edx-28]
	xor	ecx, eax
	call	@__security_check_cookie@4
	mov	ecx, DWORD PTR [edx-4]
	xor	ecx, eax
	call	@__security_check_cookie@4
	mov	eax, OFFSET __ehfuncinfo$??0SecureWord@@QAE@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@00@Z
	jmp	___CxxFrameHandler3
text$x	ENDS
??0SecureWord@@QAE@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@00@Z ENDP ; SecureWord::SecureWord
; Function compile flags: /Ogtp
;	COMDAT ?code@SecureWord@@QAEXXZ
_TEXT	SEGMENT
?code@SecureWord@@QAEXXZ PROC				; SecureWord::code, COMDAT
; _this$ = ecx
; File e:\csgo\project6\project6\secureword.cpp
; Line 59
	push	esi
; Line 61
	xor	esi, esi
	cmp	DWORD PTR [ecx+16], esi
	jbe	$LN135@code
	push	ebx
	push	edi
	lea	ebx, DWORD PTR [esi+26]
$LL4@code:
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstring
; Line 1825
	mov	edi, DWORD PTR [ecx+20]
; Line 1803
	mov	eax, ecx
; Line 1825
	cmp	edi, 16					; 00000010H
; Line 1804
	jb	SHORT $LN132@code
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstddef
; Line 346
	mov	eax, DWORD PTR [ecx]
$LN132@code:
; File e:\csgo\project6\project6\secureword.cpp
; Line 63
	cmp	BYTE PTR [eax+esi], 122			; 0000007aH
	jg	SHORT $LN5@code
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstring
; Line 1803
	mov	eax, ecx
; Line 1825
	cmp	edi, 16					; 00000010H
; Line 1804
	jb	SHORT $LN129@code
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstddef
; Line 346
	mov	eax, DWORD PTR [ecx]
$LN129@code:
; File e:\csgo\project6\project6\secureword.cpp
; Line 63
	cmp	BYTE PTR [eax+esi], 97			; 00000061H
	jl	SHORT $LN5@code
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstring
; Line 1803
	mov	eax, ecx
; Line 1825
	cmp	edi, 16					; 00000010H
; Line 1804
	jb	SHORT $LN133@code
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstddef
; Line 346
	mov	eax, DWORD PTR [ecx]
$LN133@code:
; File e:\csgo\project6\project6\secureword.cpp
; Line 66
	movsx	edx, BYTE PTR [eax+esi]
	mov	eax, DWORD PTR [ecx+28]
	add	eax, -97				; ffffff9fH
	add	eax, edx
	cdq
	idiv	ebx
	add	dl, 97					; 00000061H
	jmp	SHORT $LN138@code
$LN5@code:
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstring
; Line 1803
	mov	eax, ecx
; Line 1825
	cmp	edi, 16					; 00000010H
; Line 1804
	jb	SHORT $LN130@code
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstddef
; Line 346
	mov	eax, DWORD PTR [ecx]
$LN130@code:
; File e:\csgo\project6\project6\secureword.cpp
; Line 69
	cmp	BYTE PTR [eax+esi], 90			; 0000005aH
	jg	SHORT $LN2@code
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstring
; Line 1803
	mov	eax, ecx
; Line 1825
	cmp	edi, 16					; 00000010H
; Line 1804
	jb	SHORT $LN131@code
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstddef
; Line 346
	mov	eax, DWORD PTR [ecx]
$LN131@code:
; File e:\csgo\project6\project6\secureword.cpp
; Line 69
	cmp	BYTE PTR [eax+esi], 65			; 00000041H
	jl	SHORT $LN2@code
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstring
; Line 1803
	mov	eax, ecx
; Line 1825
	cmp	edi, 16					; 00000010H
; Line 1804
	jb	SHORT $LN134@code
; File e:\visualstudio\vc\tools\msvc\14.16.27023\include\xstddef
; Line 346
	mov	eax, DWORD PTR [ecx]
$LN134@code:
; File e:\csgo\project6\project6\secureword.cpp
; Line 72
	movsx	edx, BYTE PTR [eax+esi]
	mov	eax, DWORD PTR [ecx+28]
	add	eax, -65				; ffffffbfH
	add	eax, edx
	cdq
	idiv	ebx
	add	dl, 65					; 00000041H
$LN138@code:
; Line 61
	mov	eax, ecx
	cmp	edi, 16					; 00000010H
	jb	SHORT $LN113@code
	mov	eax, DWORD PTR [ecx]
$LN113@code:
	mov	BYTE PTR [eax+esi], dl
$LN2@code:
	inc	esi
	cmp	esi, DWORD PTR [ecx+16]
	jb	$LL4@code
; Line 76
	pop	edi
	pop	ebx
$LN135@code:
; Line 77
	mov	BYTE PTR [ecx+24], 1
	pop	esi
	ret	0
?code@SecureWord@@QAEXXZ ENDP				; SecureWord::code
_TEXT	ENDS
; Function compile flags: /Ogtp
;	COMDAT ?getword@SecureWord@@QAE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
_TEXT	SEGMENT
___$ReturnUdt$ = 8					; size = 4
?getword@SecureWord@@QAE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ PROC ; SecureWord::getword, COMDAT
; _this$ = ecx
; File e:\csgo\project6\project6\secureword.cpp
; Line 80
	push	ebp
	mov	ebp, esp
; Line 81
	push	ecx
	mov	ecx, DWORD PTR ___$ReturnUdt$[ebp]
	call	??0?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QAE@ABV01@@Z ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::basic_string<char,std::char_traits<char>,std::allocator<char> >
	mov	eax, DWORD PTR ___$ReturnUdt$[ebp]
; Line 82
	pop	ebp
	ret	4
?getword@SecureWord@@QAE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ ENDP ; SecureWord::getword
_TEXT	ENDS
END
