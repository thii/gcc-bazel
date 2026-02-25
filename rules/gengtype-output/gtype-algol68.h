/* Type information for algol68.
   Copyright (C) 2004-2026 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

/* This file is machine generated.  Do not edit.  */

void
gt_ggc_mx_NODE_T (void *x_p)
{
  struct NODE_T * x = (struct NODE_T *)x_p;
  struct NODE_T * xlimit = x;
  while (ggc_test_and_set_mark (xlimit))
   xlimit = ((*xlimit).next);
  if (x != xlimit)
    for (;;)
      {
        struct NODE_T * const xprev = ((*x).previous);
        if (xprev == NULL) break;
        x = xprev;
        (void) ggc_test_and_set_mark (xprev);
      }
  while (x != xlimit)
    {
      gt_ggc_m_7GINFO_T ((*x).genie);
      gt_ggc_m_6MOID_T ((*x).type);
      gt_ggc_m_11NODE_INFO_T ((*x).info);
      gt_ggc_m_6NODE_T ((*x).next);
      gt_ggc_m_6NODE_T ((*x).previous);
      gt_ggc_m_6NODE_T ((*x).sub);
      gt_ggc_m_6NODE_T ((*x).sequence);
      gt_ggc_m_6NODE_T ((*x).nest);
      gt_ggc_m_6PACK_T ((*x).pack);
      gt_ggc_m_7TABLE_T ((*x).symbol_table);
      gt_ggc_m_7TABLE_T ((*x).non_local);
      gt_ggc_m_5TAG_T ((*x).tag);
      gt_ggc_m_9tree_node ((*x).cdecl);
      x = ((*x).next);
    }
}

void
gt_ggc_mx_MOID_T (void *x_p)
{
  struct MOID_T * x = (struct MOID_T *)x_p;
  struct MOID_T * xlimit = x;
  while (ggc_test_and_set_mark (xlimit))
   xlimit = ((*xlimit).next);
  while (x != xlimit)
    {
      gt_ggc_m_6NODE_T ((*x).node);
      gt_ggc_m_6PACK_T ((*x).pack);
      gt_ggc_m_6MOID_T ((*x).sub);
      gt_ggc_m_6MOID_T ((*x).equivalent_mode);
      gt_ggc_m_6MOID_T ((*x).slice);
      gt_ggc_m_6MOID_T ((*x).deflexed_mode);
      gt_ggc_m_6MOID_T ((*x).name);
      gt_ggc_m_6MOID_T ((*x).multiple_mode);
      gt_ggc_m_6MOID_T ((*x).next);
      gt_ggc_m_6MOID_T ((*x).rowed);
      gt_ggc_m_6MOID_T ((*x).trim);
      gt_ggc_m_9tree_node ((*x).ctype);
      gt_ggc_m_S ((*x).asm_label);
      x = ((*x).next);
    }
}

void
gt_ggc_mx_GINFO_T (void *x_p)
{
  struct GINFO_T * const x = (struct GINFO_T *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      gt_ggc_m_6MOID_T ((*x).partial_proc);
      gt_ggc_m_6MOID_T ((*x).partial_locale);
    }
}

void
gt_ggc_mx_KEYWORD_T (void *x_p)
{
  struct KEYWORD_T * x = (struct KEYWORD_T *)x_p;
  struct KEYWORD_T * xlimit = x;
  while (ggc_test_and_set_mark (xlimit))
   xlimit = ((*xlimit).more);
  if (x != xlimit)
    for (;;)
      {
        struct KEYWORD_T * const xprev = ((*x).less);
        if (xprev == NULL) break;
        x = xprev;
        (void) ggc_test_and_set_mark (xprev);
      }
  while (x != xlimit)
    {
      gt_ggc_m_S ((*x).text);
      gt_ggc_m_9KEYWORD_T ((*x).less);
      gt_ggc_m_9KEYWORD_T ((*x).more);
      x = ((*x).more);
    }
}

void
gt_ggc_mx_LINE_T (void *x_p)
{
  struct LINE_T * x = (struct LINE_T *)x_p;
  struct LINE_T * xlimit = x;
  while (ggc_test_and_set_mark (xlimit))
   xlimit = ((*xlimit).next);
  while (x != xlimit)
    {
      gt_ggc_m_S ((*x).filename);
      gt_ggc_m_6LINE_T ((*x).next);
      gt_ggc_m_6LINE_T ((*x).previous);
      x = ((*x).next);
    }
}

void
gt_ggc_mx_NODE_INFO_T (void *x_p)
{
  struct NODE_INFO_T * const x = (struct NODE_INFO_T *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      gt_ggc_m_6LINE_T ((*x).comment_line);
      gt_ggc_m_6LINE_T ((*x).pragmat_line);
      gt_ggc_m_S ((*x).symbol);
      gt_ggc_m_6LINE_T ((*x).line);
    }
}

void
gt_ggc_mx_PACK_T (void *x_p)
{
  struct PACK_T * x = (struct PACK_T *)x_p;
  struct PACK_T * xlimit = x;
  while (ggc_test_and_set_mark (xlimit))
   xlimit = ((*xlimit).next);
  if (x != xlimit)
    for (;;)
      {
        struct PACK_T * const xprev = ((*x).previous);
        if (xprev == NULL) break;
        x = xprev;
        (void) ggc_test_and_set_mark (xprev);
      }
  while (x != xlimit)
    {
      gt_ggc_m_6MOID_T ((*x).type);
      gt_ggc_m_S ((*x).text);
      gt_ggc_m_6NODE_T ((*x).node);
      gt_ggc_m_6PACK_T ((*x).next);
      gt_ggc_m_6PACK_T ((*x).previous);
      x = ((*x).next);
    }
}

void
gt_ggc_mx_SOID_T (void *x_p)
{
  struct SOID_T * x = (struct SOID_T *)x_p;
  struct SOID_T * xlimit = x;
  while (ggc_test_and_set_mark (xlimit))
   xlimit = ((*xlimit).next);
  while (x != xlimit)
    {
      gt_ggc_m_6MOID_T ((*x).type);
      gt_ggc_m_6NODE_T ((*x).node);
      gt_ggc_m_6SOID_T ((*x).next);
      x = ((*x).next);
    }
}

void
gt_ggc_mx_TABLE_T (void *x_p)
{
  struct TABLE_T * const x = (struct TABLE_T *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      gt_ggc_m_7TABLE_T ((*x).previous);
      gt_ggc_m_7TABLE_T ((*x).outer);
      gt_ggc_m_5TAG_T ((*x).identifiers);
      gt_ggc_m_5TAG_T ((*x).operators);
      gt_ggc_m_5TAG_T ((*x).modules);
      gt_ggc_m_5TAG_T ((*x).priority);
      gt_ggc_m_5TAG_T ((*x).indicants);
      gt_ggc_m_5TAG_T ((*x).labels);
      gt_ggc_m_5TAG_T ((*x).anonymous);
      gt_ggc_m_6NODE_T ((*x).jump_to);
      gt_ggc_m_6NODE_T ((*x).sequence);
    }
}

void
gt_ggc_mx_TAG_T (void *x_p)
{
  struct TAG_T * x = (struct TAG_T *)x_p;
  struct TAG_T * xlimit = x;
  while (ggc_test_and_set_mark (xlimit))
   xlimit = ((*xlimit).next);
  while (x != xlimit)
    {
      gt_ggc_m_7TABLE_T ((*x).symbol_table);
      gt_ggc_m_6MOID_T ((*x).type);
      gt_ggc_m_6NODE_T ((*x).node);
      gt_ggc_m_6NODE_T ((*x).unit);
      gt_ggc_m_S ((*x).value);
      gt_ggc_m_9tree_node ((*x).tree_decl);
      gt_ggc_m_6MOIF_T ((*x).moif);
      gt_ggc_m_5TAG_T ((*x).next);
      gt_ggc_m_5TAG_T ((*x).body);
      gt_ggc_m_S ((*x).extern_symbol);
      x = ((*x).next);
    }
}

void
gt_ggc_mx_TOKEN_T (void *x_p)
{
  struct TOKEN_T * x = (struct TOKEN_T *)x_p;
  struct TOKEN_T * xlimit = x;
  while (ggc_test_and_set_mark (xlimit))
   xlimit = ((*xlimit).more);
  if (x != xlimit)
    for (;;)
      {
        struct TOKEN_T * const xprev = ((*x).less);
        if (xprev == NULL) break;
        x = xprev;
        (void) ggc_test_and_set_mark (xprev);
      }
  while (x != xlimit)
    {
      gt_ggc_m_S ((*x).text);
      gt_ggc_m_7TOKEN_T ((*x).less);
      gt_ggc_m_7TOKEN_T ((*x).more);
      x = ((*x).more);
    }
}

void
gt_ggc_mx_POSTULATE_T (void *x_p)
{
  struct POSTULATE_T * x = (struct POSTULATE_T *)x_p;
  struct POSTULATE_T * xlimit = x;
  while (ggc_test_and_set_mark (xlimit))
   xlimit = ((*xlimit).next);
  while (x != xlimit)
    {
      gt_ggc_m_6MOID_T ((*x).a);
      gt_ggc_m_6MOID_T ((*x).b);
      gt_ggc_m_11POSTULATE_T ((*x).next);
      x = ((*x).next);
    }
}

void
gt_ggc_mx_OPTIONS_T (void *x_p)
{
  struct OPTIONS_T * const x = (struct OPTIONS_T *)x_p;
  if (ggc_test_and_set_mark (x))
    {
    }
}

void
gt_ggc_mx_EXTRACT_T (void *x_p)
{
  struct EXTRACT_T * const x = (struct EXTRACT_T *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      gt_ggc_m_S ((*x).symbol);
      gt_ggc_m_6MOID_T ((*x).mode);
    }
}

void
gt_ggc_mx_MOIF_T (void *x_p)
{
  struct MOIF_T * x = (struct MOIF_T *)x_p;
  struct MOIF_T * xlimit = x;
  while (ggc_test_and_set_mark (xlimit))
   xlimit = ((*xlimit).next);
  while (x != xlimit)
    {
      gt_ggc_m_S ((*x).name);
      gt_ggc_m_S ((*x).prelude);
      gt_ggc_m_S ((*x).postlude);
      gt_ggc_m_18vec_MOID_T__va_gc_ ((*x).modes);
      gt_ggc_m_21vec_EXTRACT_T__va_gc_ ((*x).modules);
      gt_ggc_m_21vec_EXTRACT_T__va_gc_ ((*x).indicants);
      gt_ggc_m_21vec_EXTRACT_T__va_gc_ ((*x).identifiers);
      gt_ggc_m_21vec_EXTRACT_T__va_gc_ ((*x).prios);
      gt_ggc_m_21vec_EXTRACT_T__va_gc_ ((*x).operators);
      gt_ggc_m_6MOIF_T ((*x).next);
      x = ((*x).next);
    }
}

void
gt_ggc_mx_vec_MOID_T__va_gc_ (void *x_p)
{
  vec<MOID_T*,va_gc> * const x = (vec<MOID_T*,va_gc> *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      gt_ggc_mx (x);
    }
}

void
gt_ggc_mx (struct MOID_T *& x)
{
  if (x)
    gt_ggc_mx_MOID_T ((void *) x);
}

void
gt_ggc_mx_vec_EXTRACT_T__va_gc_ (void *x_p)
{
  vec<EXTRACT_T*,va_gc> * const x = (vec<EXTRACT_T*,va_gc> *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      gt_ggc_mx (x);
    }
}

void
gt_ggc_mx (struct EXTRACT_T *& x)
{
  if (x)
    gt_ggc_mx_EXTRACT_T ((void *) x);
}

void
gt_ggc_mx_vec_char__va_gc_vl_embed_ (void *x_p)
{
  vec<char*,va_gc,vl_embed> * const x = (vec<char*,va_gc,vl_embed> *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      gt_ggc_mx (x);
    }
}

void
gt_ggc_mx_hash_map_nofree_string_hash_char__ (void *x_p)
{
  hash_map<nofree_string_hash,char*> * const x = (hash_map<nofree_string_hash,char*> *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      gt_ggc_mx (x);
    }
}

void
gt_pch_nx_NODE_T (void *x_p)
{
  struct NODE_T * x = (struct NODE_T *)x_p;
  struct NODE_T * xlimit = x;
  while (gt_pch_note_object (xlimit, xlimit, gt_pch_p_6NODE_T))
   xlimit = ((*xlimit).next);
  if (x != xlimit)
    for (;;)
      {
        struct NODE_T * const xprev = ((*x).previous);
        if (xprev == NULL) break;
        x = xprev;
        (void) gt_pch_note_object (xprev, xprev, gt_pch_p_6NODE_T);
      }
  while (x != xlimit)
    {
      gt_pch_n_7GINFO_T ((*x).genie);
      gt_pch_n_6MOID_T ((*x).type);
      gt_pch_n_11NODE_INFO_T ((*x).info);
      gt_pch_n_6NODE_T ((*x).next);
      gt_pch_n_6NODE_T ((*x).previous);
      gt_pch_n_6NODE_T ((*x).sub);
      gt_pch_n_6NODE_T ((*x).sequence);
      gt_pch_n_6NODE_T ((*x).nest);
      gt_pch_n_6PACK_T ((*x).pack);
      gt_pch_n_7TABLE_T ((*x).symbol_table);
      gt_pch_n_7TABLE_T ((*x).non_local);
      gt_pch_n_5TAG_T ((*x).tag);
      gt_pch_n_9tree_node ((*x).cdecl);
      x = ((*x).next);
    }
}

void
gt_pch_nx_MOID_T (void *x_p)
{
  struct MOID_T * x = (struct MOID_T *)x_p;
  struct MOID_T * xlimit = x;
  while (gt_pch_note_object (xlimit, xlimit, gt_pch_p_6MOID_T))
   xlimit = ((*xlimit).next);
  while (x != xlimit)
    {
      gt_pch_n_6NODE_T ((*x).node);
      gt_pch_n_6PACK_T ((*x).pack);
      gt_pch_n_6MOID_T ((*x).sub);
      gt_pch_n_6MOID_T ((*x).equivalent_mode);
      gt_pch_n_6MOID_T ((*x).slice);
      gt_pch_n_6MOID_T ((*x).deflexed_mode);
      gt_pch_n_6MOID_T ((*x).name);
      gt_pch_n_6MOID_T ((*x).multiple_mode);
      gt_pch_n_6MOID_T ((*x).next);
      gt_pch_n_6MOID_T ((*x).rowed);
      gt_pch_n_6MOID_T ((*x).trim);
      gt_pch_n_9tree_node ((*x).ctype);
      gt_pch_n_S ((*x).asm_label);
      x = ((*x).next);
    }
}

void
gt_pch_nx_GINFO_T (void *x_p)
{
  struct GINFO_T * const x = (struct GINFO_T *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_7GINFO_T))
    {
      gt_pch_n_6MOID_T ((*x).partial_proc);
      gt_pch_n_6MOID_T ((*x).partial_locale);
    }
}

void
gt_pch_nx_KEYWORD_T (void *x_p)
{
  struct KEYWORD_T * x = (struct KEYWORD_T *)x_p;
  struct KEYWORD_T * xlimit = x;
  while (gt_pch_note_object (xlimit, xlimit, gt_pch_p_9KEYWORD_T))
   xlimit = ((*xlimit).more);
  if (x != xlimit)
    for (;;)
      {
        struct KEYWORD_T * const xprev = ((*x).less);
        if (xprev == NULL) break;
        x = xprev;
        (void) gt_pch_note_object (xprev, xprev, gt_pch_p_9KEYWORD_T);
      }
  while (x != xlimit)
    {
      gt_pch_n_S ((*x).text);
      gt_pch_n_9KEYWORD_T ((*x).less);
      gt_pch_n_9KEYWORD_T ((*x).more);
      x = ((*x).more);
    }
}

void
gt_pch_nx_LINE_T (void *x_p)
{
  struct LINE_T * x = (struct LINE_T *)x_p;
  struct LINE_T * xlimit = x;
  while (gt_pch_note_object (xlimit, xlimit, gt_pch_p_6LINE_T))
   xlimit = ((*xlimit).next);
  while (x != xlimit)
    {
      gt_pch_n_S ((*x).filename);
      gt_pch_n_6LINE_T ((*x).next);
      gt_pch_n_6LINE_T ((*x).previous);
      x = ((*x).next);
    }
}

void
gt_pch_nx_NODE_INFO_T (void *x_p)
{
  struct NODE_INFO_T * const x = (struct NODE_INFO_T *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_11NODE_INFO_T))
    {
      gt_pch_n_6LINE_T ((*x).comment_line);
      gt_pch_n_6LINE_T ((*x).pragmat_line);
      gt_pch_n_S ((*x).symbol);
      gt_pch_n_6LINE_T ((*x).line);
    }
}

void
gt_pch_nx_PACK_T (void *x_p)
{
  struct PACK_T * x = (struct PACK_T *)x_p;
  struct PACK_T * xlimit = x;
  while (gt_pch_note_object (xlimit, xlimit, gt_pch_p_6PACK_T))
   xlimit = ((*xlimit).next);
  if (x != xlimit)
    for (;;)
      {
        struct PACK_T * const xprev = ((*x).previous);
        if (xprev == NULL) break;
        x = xprev;
        (void) gt_pch_note_object (xprev, xprev, gt_pch_p_6PACK_T);
      }
  while (x != xlimit)
    {
      gt_pch_n_6MOID_T ((*x).type);
      gt_pch_n_S ((*x).text);
      gt_pch_n_6NODE_T ((*x).node);
      gt_pch_n_6PACK_T ((*x).next);
      gt_pch_n_6PACK_T ((*x).previous);
      x = ((*x).next);
    }
}

void
gt_pch_nx_SOID_T (void *x_p)
{
  struct SOID_T * x = (struct SOID_T *)x_p;
  struct SOID_T * xlimit = x;
  while (gt_pch_note_object (xlimit, xlimit, gt_pch_p_6SOID_T))
   xlimit = ((*xlimit).next);
  while (x != xlimit)
    {
      gt_pch_n_6MOID_T ((*x).type);
      gt_pch_n_6NODE_T ((*x).node);
      gt_pch_n_6SOID_T ((*x).next);
      x = ((*x).next);
    }
}

void
gt_pch_nx_TABLE_T (void *x_p)
{
  struct TABLE_T * const x = (struct TABLE_T *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_7TABLE_T))
    {
      gt_pch_n_7TABLE_T ((*x).previous);
      gt_pch_n_7TABLE_T ((*x).outer);
      gt_pch_n_5TAG_T ((*x).identifiers);
      gt_pch_n_5TAG_T ((*x).operators);
      gt_pch_n_5TAG_T ((*x).modules);
      gt_pch_n_5TAG_T ((*x).priority);
      gt_pch_n_5TAG_T ((*x).indicants);
      gt_pch_n_5TAG_T ((*x).labels);
      gt_pch_n_5TAG_T ((*x).anonymous);
      gt_pch_n_6NODE_T ((*x).jump_to);
      gt_pch_n_6NODE_T ((*x).sequence);
    }
}

void
gt_pch_nx_TAG_T (void *x_p)
{
  struct TAG_T * x = (struct TAG_T *)x_p;
  struct TAG_T * xlimit = x;
  while (gt_pch_note_object (xlimit, xlimit, gt_pch_p_5TAG_T))
   xlimit = ((*xlimit).next);
  while (x != xlimit)
    {
      gt_pch_n_7TABLE_T ((*x).symbol_table);
      gt_pch_n_6MOID_T ((*x).type);
      gt_pch_n_6NODE_T ((*x).node);
      gt_pch_n_6NODE_T ((*x).unit);
      gt_pch_n_S ((*x).value);
      gt_pch_n_9tree_node ((*x).tree_decl);
      gt_pch_n_6MOIF_T ((*x).moif);
      gt_pch_n_5TAG_T ((*x).next);
      gt_pch_n_5TAG_T ((*x).body);
      gt_pch_n_S ((*x).extern_symbol);
      x = ((*x).next);
    }
}

void
gt_pch_nx_TOKEN_T (void *x_p)
{
  struct TOKEN_T * x = (struct TOKEN_T *)x_p;
  struct TOKEN_T * xlimit = x;
  while (gt_pch_note_object (xlimit, xlimit, gt_pch_p_7TOKEN_T))
   xlimit = ((*xlimit).more);
  if (x != xlimit)
    for (;;)
      {
        struct TOKEN_T * const xprev = ((*x).less);
        if (xprev == NULL) break;
        x = xprev;
        (void) gt_pch_note_object (xprev, xprev, gt_pch_p_7TOKEN_T);
      }
  while (x != xlimit)
    {
      gt_pch_n_S ((*x).text);
      gt_pch_n_7TOKEN_T ((*x).less);
      gt_pch_n_7TOKEN_T ((*x).more);
      x = ((*x).more);
    }
}

void
gt_pch_nx_POSTULATE_T (void *x_p)
{
  struct POSTULATE_T * x = (struct POSTULATE_T *)x_p;
  struct POSTULATE_T * xlimit = x;
  while (gt_pch_note_object (xlimit, xlimit, gt_pch_p_11POSTULATE_T))
   xlimit = ((*xlimit).next);
  while (x != xlimit)
    {
      gt_pch_n_6MOID_T ((*x).a);
      gt_pch_n_6MOID_T ((*x).b);
      gt_pch_n_11POSTULATE_T ((*x).next);
      x = ((*x).next);
    }
}

void
gt_pch_nx_OPTIONS_T (void *x_p)
{
  struct OPTIONS_T * const x = (struct OPTIONS_T *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_9OPTIONS_T))
    {
    }
}

void
gt_pch_nx_EXTRACT_T (void *x_p)
{
  struct EXTRACT_T * const x = (struct EXTRACT_T *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_9EXTRACT_T))
    {
      gt_pch_n_S ((*x).symbol);
      gt_pch_n_6MOID_T ((*x).mode);
    }
}

void
gt_pch_nx_MOIF_T (void *x_p)
{
  struct MOIF_T * x = (struct MOIF_T *)x_p;
  struct MOIF_T * xlimit = x;
  while (gt_pch_note_object (xlimit, xlimit, gt_pch_p_6MOIF_T))
   xlimit = ((*xlimit).next);
  while (x != xlimit)
    {
      gt_pch_n_S ((*x).name);
      gt_pch_n_S ((*x).prelude);
      gt_pch_n_S ((*x).postlude);
      gt_pch_n_18vec_MOID_T__va_gc_ ((*x).modes);
      gt_pch_n_21vec_EXTRACT_T__va_gc_ ((*x).modules);
      gt_pch_n_21vec_EXTRACT_T__va_gc_ ((*x).indicants);
      gt_pch_n_21vec_EXTRACT_T__va_gc_ ((*x).identifiers);
      gt_pch_n_21vec_EXTRACT_T__va_gc_ ((*x).prios);
      gt_pch_n_21vec_EXTRACT_T__va_gc_ ((*x).operators);
      gt_pch_n_6MOIF_T ((*x).next);
      x = ((*x).next);
    }
}

void
gt_pch_nx_vec_MOID_T__va_gc_ (void *x_p)
{
  vec<MOID_T*,va_gc> * const x = (vec<MOID_T*,va_gc> *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_18vec_MOID_T__va_gc_))
    {
      gt_pch_nx (x);
    }
}

void
gt_pch_nx (struct MOID_T *& x)
{
  if (x)
    gt_pch_nx_MOID_T ((void *) x);
}

void
gt_pch_nx_vec_EXTRACT_T__va_gc_ (void *x_p)
{
  vec<EXTRACT_T*,va_gc> * const x = (vec<EXTRACT_T*,va_gc> *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_21vec_EXTRACT_T__va_gc_))
    {
      gt_pch_nx (x);
    }
}

void
gt_pch_nx (struct EXTRACT_T *& x)
{
  if (x)
    gt_pch_nx_EXTRACT_T ((void *) x);
}

void
gt_pch_nx_vec_char__va_gc_vl_embed_ (void *x_p)
{
  vec<char*,va_gc,vl_embed> * const x = (vec<char*,va_gc,vl_embed> *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_25vec_char__va_gc_vl_embed_))
    {
      gt_pch_nx (x);
    }
}

void
gt_pch_nx_hash_map_nofree_string_hash_char__ (void *x_p)
{
  hash_map<nofree_string_hash,char*> * const x = (hash_map<nofree_string_hash,char*> *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_34hash_map_nofree_string_hash_char__))
    {
      gt_pch_nx (x);
    }
}

void
gt_pch_p_6NODE_T (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct NODE_T * x ATTRIBUTE_UNUSED = (struct NODE_T *)x_p;
  if ((void *)(x) == this_obj)
    op (&((*x).genie), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).type), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).info), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).next), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).previous), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).sub), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).sequence), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).nest), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).pack), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).symbol_table), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).non_local), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).tag), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).cdecl), NULL, cookie);
}

void
gt_pch_p_6MOID_T (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct MOID_T * x ATTRIBUTE_UNUSED = (struct MOID_T *)x_p;
  if ((void *)(x) == this_obj)
    op (&((*x).node), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).pack), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).sub), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).equivalent_mode), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).slice), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).deflexed_mode), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).name), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).multiple_mode), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).next), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).rowed), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).trim), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).ctype), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).asm_label), NULL, cookie);
}

void
gt_pch_p_7GINFO_T (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct GINFO_T * x ATTRIBUTE_UNUSED = (struct GINFO_T *)x_p;
  if ((void *)(x) == this_obj)
    op (&((*x).partial_proc), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).partial_locale), NULL, cookie);
}

void
gt_pch_p_9KEYWORD_T (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct KEYWORD_T * x ATTRIBUTE_UNUSED = (struct KEYWORD_T *)x_p;
  if ((void *)(x) == this_obj)
    op (&((*x).text), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).less), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).more), NULL, cookie);
}

void
gt_pch_p_6LINE_T (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct LINE_T * x ATTRIBUTE_UNUSED = (struct LINE_T *)x_p;
  if ((void *)(x) == this_obj)
    op (&((*x).filename), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).next), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).previous), NULL, cookie);
}

void
gt_pch_p_11NODE_INFO_T (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct NODE_INFO_T * x ATTRIBUTE_UNUSED = (struct NODE_INFO_T *)x_p;
  if ((void *)(x) == this_obj)
    op (&((*x).comment_line), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).pragmat_line), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).symbol), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).line), NULL, cookie);
}

void
gt_pch_p_6PACK_T (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct PACK_T * x ATTRIBUTE_UNUSED = (struct PACK_T *)x_p;
  if ((void *)(x) == this_obj)
    op (&((*x).type), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).text), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).node), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).next), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).previous), NULL, cookie);
}

void
gt_pch_p_6SOID_T (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct SOID_T * x ATTRIBUTE_UNUSED = (struct SOID_T *)x_p;
  if ((void *)(x) == this_obj)
    op (&((*x).type), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).node), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).next), NULL, cookie);
}

void
gt_pch_p_7TABLE_T (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct TABLE_T * x ATTRIBUTE_UNUSED = (struct TABLE_T *)x_p;
  if ((void *)(x) == this_obj)
    op (&((*x).previous), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).outer), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).identifiers), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).operators), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).modules), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).priority), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).indicants), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).labels), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).anonymous), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).jump_to), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).sequence), NULL, cookie);
}

void
gt_pch_p_5TAG_T (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct TAG_T * x ATTRIBUTE_UNUSED = (struct TAG_T *)x_p;
  if ((void *)(x) == this_obj)
    op (&((*x).symbol_table), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).type), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).node), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).unit), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).value), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).tree_decl), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).moif), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).next), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).body), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).extern_symbol), NULL, cookie);
}

void
gt_pch_p_7TOKEN_T (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct TOKEN_T * x ATTRIBUTE_UNUSED = (struct TOKEN_T *)x_p;
  if ((void *)(x) == this_obj)
    op (&((*x).text), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).less), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).more), NULL, cookie);
}

void
gt_pch_p_11POSTULATE_T (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct POSTULATE_T * x ATTRIBUTE_UNUSED = (struct POSTULATE_T *)x_p;
  if ((void *)(x) == this_obj)
    op (&((*x).a), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).b), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).next), NULL, cookie);
}

void
gt_pch_p_9OPTIONS_T (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct OPTIONS_T * x ATTRIBUTE_UNUSED = (struct OPTIONS_T *)x_p;
}

void
gt_pch_p_9EXTRACT_T (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct EXTRACT_T * x ATTRIBUTE_UNUSED = (struct EXTRACT_T *)x_p;
  if ((void *)(x) == this_obj)
    op (&((*x).symbol), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).mode), NULL, cookie);
}

void
gt_pch_p_6MOIF_T (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct MOIF_T * x ATTRIBUTE_UNUSED = (struct MOIF_T *)x_p;
  if ((void *)(x) == this_obj)
    op (&((*x).name), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).prelude), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).postlude), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).modes), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).modules), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).indicants), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).identifiers), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).prios), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).operators), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).next), NULL, cookie);
}

void
gt_pch_p_18vec_MOID_T__va_gc_ (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct vec<MOID_T*,va_gc> * x ATTRIBUTE_UNUSED = (struct vec<MOID_T*,va_gc> *)x_p;
  if ((void *)(x) == this_obj)
    gt_pch_nx (&((*x)), op, cookie);
}

void
gt_pch_p_21vec_EXTRACT_T__va_gc_ (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct vec<EXTRACT_T*,va_gc> * x ATTRIBUTE_UNUSED = (struct vec<EXTRACT_T*,va_gc> *)x_p;
  if ((void *)(x) == this_obj)
    gt_pch_nx (&((*x)), op, cookie);
}

void
gt_pch_p_25vec_char__va_gc_vl_embed_ (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct vec<char*,va_gc,vl_embed> * x ATTRIBUTE_UNUSED = (struct vec<char*,va_gc,vl_embed> *)x_p;
  if ((void *)(x) == this_obj)
    gt_pch_nx (&((*x)), op, cookie);
}

void
gt_pch_p_34hash_map_nofree_string_hash_char__ (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct hash_map<nofree_string_hash,char*> * x ATTRIBUTE_UNUSED = (struct hash_map<nofree_string_hash,char*> *)x_p;
  if ((void *)(x) == this_obj)
    gt_pch_nx (&((*x)), op, cookie);
}

/* GC roots.  */

EXPORTED_CONST struct ggc_root_tab gt_ggc_r_gtype_algol68_h[] = {
  {
    &a68_common.top_keyword,
    1,
    sizeof (a68_common.top_keyword),
    &gt_ggc_mx_KEYWORD_T,
    &gt_pch_nx_KEYWORD_T
  },
  {
    &a68_common.job.top_line,
    1,
    sizeof (a68_common.job.top_line),
    &gt_ggc_mx_LINE_T,
    &gt_pch_nx_LINE_T
  },
  {
    &a68_common.job.top_moid,
    1,
    sizeof (a68_common.job.top_moid),
    &gt_ggc_mx_MOID_T,
    &gt_pch_nx_MOID_T
  },
  {
    &a68_common.job.standenv_moid,
    1,
    sizeof (a68_common.job.standenv_moid),
    &gt_ggc_mx_MOID_T,
    &gt_pch_nx_MOID_T
  },
  {
    &a68_common.job.top_moif,
    1,
    sizeof (a68_common.job.top_moif),
    &gt_ggc_mx_MOIF_T,
    &gt_pch_nx_MOIF_T
  },
  {
    &a68_common.job.top_node,
    1,
    sizeof (a68_common.job.top_node),
    &gt_ggc_mx_NODE_T,
    &gt_pch_nx_NODE_T
  },
  {
    &a68_common.job.file_source_name,
    1,
    sizeof (a68_common.job.file_source_name),
    (gt_pointer_walker) &gt_ggc_m_S,
    (gt_pointer_walker) &gt_pch_n_S
  },
  {
    &a68_common.job.scan_state.save_l,
    1,
    sizeof (a68_common.job.scan_state.save_l),
    &gt_ggc_mx_LINE_T,
    &gt_pch_nx_LINE_T
  },
  {
    &a68_common.options,
    1,
    sizeof (a68_common.options),
    &gt_ggc_mx_OPTIONS_T,
    &gt_pch_nx_OPTIONS_T
  },
  {
    &a68_common.postulates,
    1,
    sizeof (a68_common.postulates),
    &gt_ggc_mx_POSTULATE_T,
    &gt_pch_nx_POSTULATE_T
  },
  {
    &a68_common.top_postulate,
    1,
    sizeof (a68_common.top_postulate),
    &gt_ggc_mx_POSTULATE_T,
    &gt_pch_nx_POSTULATE_T
  },
  {
    &a68_common.top_postulate_list,
    1,
    sizeof (a68_common.top_postulate_list),
    &gt_ggc_mx_POSTULATE_T,
    &gt_pch_nx_POSTULATE_T
  },
  {
    &a68_common.top_soid_list,
    1,
    sizeof (a68_common.top_soid_list),
    &gt_ggc_mx_SOID_T,
    &gt_pch_nx_SOID_T
  },
  {
    &a68_common.standenv,
    1,
    sizeof (a68_common.standenv),
    &gt_ggc_mx_TABLE_T,
    &gt_pch_nx_TABLE_T
  },
  {
    &a68_common.top_token,
    1,
    sizeof (a68_common.top_token),
    &gt_ggc_mx_TOKEN_T,
    &gt_pch_nx_TOKEN_T
  },
  {
    &a68_common.include_paths,
    1,
    sizeof (a68_common.include_paths),
    &gt_ggc_mx_vec_char__va_gc_vl_embed_,
    &gt_pch_nx_vec_char__va_gc_vl_embed_
  },
  {
    &a68_common.import_paths,
    1,
    sizeof (a68_common.import_paths),
    &gt_ggc_mx_vec_char__va_gc_vl_embed_,
    &gt_pch_nx_vec_char__va_gc_vl_embed_
  },
  {
    &a68_common.module_files,
    1,
    sizeof (a68_common.module_files),
    &gt_ggc_mx_hash_map_nofree_string_hash_char__,
    &gt_pch_nx_hash_map_nofree_string_hash_char__
  },
  {
    &a68_common.global_trees[0],
    1 * (ATI_MAX),
    sizeof (a68_common.global_trees[0]),
    &gt_ggc_mx_tree_node,
    &gt_pch_nx_tree_node
  },
  {
    &a68_common.parser_state.error_tag,
    1,
    sizeof (a68_common.parser_state.error_tag),
    &gt_ggc_mx_TAG_T,
    &gt_pch_nx_TAG_T
  },
  {
    &a68_common.module_definition_decls,
    1,
    sizeof (a68_common.module_definition_decls),
    &gt_ggc_mx_vec_tree_va_gc_,
    &gt_pch_nx_vec_tree_va_gc_
  },
  {
    &a68_common.global_context,
    1,
    sizeof (a68_common.global_context),
    &gt_ggc_mx_tree_node,
    &gt_pch_nx_tree_node
  },
  {
    &a68_common.global_declarations,
    1,
    sizeof (a68_common.global_declarations),
    &gt_ggc_mx_vec_tree_va_gc_,
    &gt_pch_nx_vec_tree_va_gc_
  },
  LAST_GGC_ROOT_TAB
};

extern const struct ggc_root_tab gt_ggc_r_gt_coverage_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_symtab_thunks_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_caller_save_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_alias_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_attribs_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_cselib_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_cgraph_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_ipa_prop_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_ipa_sra_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_ipa_modref_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_dwarf2asm_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_dwarf2cfi_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_dwarf2ctf_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_dwarf2out_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_ctfout_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_btfout_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_tree_vect_generic_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_dojump_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_emit_rtl_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_explow_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_function_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_except_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_ggc_tests_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_gcse_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_godump_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_optabs_libfuncs_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_cfgrtl_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_stor_layout_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_stringpool_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_tree_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_varasm_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_tree_ssa_address_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_tree_ssa_loop_ivopts_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_gimple_expr_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_tree_scalar_evolution_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_tree_profile_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_tree_nested_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_omp_low_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_targhooks_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_i386_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_cgraphclones_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_trans_mem_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_vtable_verify_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_asan_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_ubsan_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_ipa_devirt_h[];
extern const struct ggc_root_tab gt_ggc_r_gtype_desc_cc[];
extern const struct ggc_root_tab gt_ggc_r_gt_analyzer_language_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_i386_builtins_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_i386_expand_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_i386_options_h[];
extern const struct ggc_root_tab gt_ggc_r_gtype_algol68_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_algol68_a68_low_ranges_h[];
EXPORTED_CONST struct ggc_root_tab * const gt_ggc_rtab[] = {
  gt_ggc_r_gt_coverage_h,
  gt_ggc_r_gt_symtab_thunks_h,
  gt_ggc_r_gt_caller_save_h,
  gt_ggc_r_gt_alias_h,
  gt_ggc_r_gt_attribs_h,
  gt_ggc_r_gt_cselib_h,
  gt_ggc_r_gt_cgraph_h,
  gt_ggc_r_gt_ipa_prop_h,
  gt_ggc_r_gt_ipa_sra_h,
  gt_ggc_r_gt_ipa_modref_h,
  gt_ggc_r_gt_dwarf2asm_h,
  gt_ggc_r_gt_dwarf2cfi_h,
  gt_ggc_r_gt_dwarf2ctf_h,
  gt_ggc_r_gt_dwarf2out_h,
  gt_ggc_r_gt_ctfout_h,
  gt_ggc_r_gt_btfout_h,
  gt_ggc_r_gt_tree_vect_generic_h,
  gt_ggc_r_gt_dojump_h,
  gt_ggc_r_gt_emit_rtl_h,
  gt_ggc_r_gt_explow_h,
  gt_ggc_r_gt_function_h,
  gt_ggc_r_gt_except_h,
  gt_ggc_r_gt_ggc_tests_h,
  gt_ggc_r_gt_gcse_h,
  gt_ggc_r_gt_godump_h,
  gt_ggc_r_gt_optabs_libfuncs_h,
  gt_ggc_r_gt_cfgrtl_h,
  gt_ggc_r_gt_stor_layout_h,
  gt_ggc_r_gt_stringpool_h,
  gt_ggc_r_gt_tree_h,
  gt_ggc_r_gt_varasm_h,
  gt_ggc_r_gt_tree_ssa_address_h,
  gt_ggc_r_gt_tree_ssa_loop_ivopts_h,
  gt_ggc_r_gt_gimple_expr_h,
  gt_ggc_r_gt_tree_scalar_evolution_h,
  gt_ggc_r_gt_tree_profile_h,
  gt_ggc_r_gt_tree_nested_h,
  gt_ggc_r_gt_omp_low_h,
  gt_ggc_r_gt_targhooks_h,
  gt_ggc_r_gt_i386_h,
  gt_ggc_r_gt_cgraphclones_h,
  gt_ggc_r_gt_trans_mem_h,
  gt_ggc_r_gt_vtable_verify_h,
  gt_ggc_r_gt_asan_h,
  gt_ggc_r_gt_ubsan_h,
  gt_ggc_r_gt_ipa_devirt_h,
  gt_ggc_r_gtype_desc_cc,
  gt_ggc_r_gt_analyzer_language_h,
  gt_ggc_r_gt_i386_builtins_h,
  gt_ggc_r_gt_i386_expand_h,
  gt_ggc_r_gt_i386_options_h,
  gt_ggc_r_gtype_algol68_h,
  gt_ggc_r_gt_algol68_a68_low_ranges_h,
  NULL
};
extern const struct ggc_root_tab gt_ggc_rd_gt_alias_h[];
extern const struct ggc_root_tab gt_ggc_rd_gt_bitmap_h[];
extern const struct ggc_root_tab gt_ggc_rd_gt_emit_rtl_h[];
extern const struct ggc_root_tab gt_ggc_rd_gt_ggc_tests_h[];
extern const struct ggc_root_tab gt_ggc_rd_gt_lists_h[];
extern const struct ggc_root_tab gt_ggc_rd_gt_tree_iterator_h[];
extern const struct ggc_root_tab gt_ggc_rd_gt_tree_phinodes_h[];
extern const struct ggc_root_tab gt_ggc_rd_gt_ipa_strub_h[];
EXPORTED_CONST struct ggc_root_tab * const gt_ggc_deletable_rtab[] = {
  gt_ggc_rd_gt_alias_h,
  gt_ggc_rd_gt_bitmap_h,
  gt_ggc_rd_gt_emit_rtl_h,
  gt_ggc_rd_gt_ggc_tests_h,
  gt_ggc_rd_gt_lists_h,
  gt_ggc_rd_gt_tree_iterator_h,
  gt_ggc_rd_gt_tree_phinodes_h,
  gt_ggc_rd_gt_ipa_strub_h,
  NULL
};
extern void gt_clear_caches_gt_ipa_prop_h ();
extern void gt_clear_caches_gt_emit_rtl_h ();
extern void gt_clear_caches_gt_function_h ();
extern void gt_clear_caches_gt_tree_h ();
extern void gt_clear_caches_gt_varasm_h ();
extern void gt_clear_caches_gt_trans_mem_h ();
extern void gt_clear_caches_gt_ubsan_h ();
void
gt_clear_caches ()
{
  gt_clear_caches_gt_ipa_prop_h ();
  gt_clear_caches_gt_emit_rtl_h ();
  gt_clear_caches_gt_function_h ();
  gt_clear_caches_gt_tree_h ();
  gt_clear_caches_gt_varasm_h ();
  gt_clear_caches_gt_trans_mem_h ();
  gt_clear_caches_gt_ubsan_h ();
}
EXPORTED_CONST struct ggc_root_tab gt_pch_rs_gtype_algol68_h[] = {
  { &a68_common, 1, sizeof (a68_common), NULL, NULL },
  LAST_GGC_ROOT_TAB
};

extern const struct ggc_root_tab gt_pch_rs_gt_alias_h[];
extern const struct ggc_root_tab gt_pch_rs_gt_dwarf2asm_h[];
extern const struct ggc_root_tab gt_pch_rs_gt_dwarf2cfi_h[];
extern const struct ggc_root_tab gt_pch_rs_gt_dwarf2out_h[];
extern const struct ggc_root_tab gt_pch_rs_gt_tree_vect_generic_h[];
extern const struct ggc_root_tab gt_pch_rs_gt_emit_rtl_h[];
extern const struct ggc_root_tab gt_pch_rs_gt_function_h[];
extern const struct ggc_root_tab gt_pch_rs_gt_except_h[];
extern const struct ggc_root_tab gt_pch_rs_gt_tree_h[];
extern const struct ggc_root_tab gt_pch_rs_gt_varasm_h[];
extern const struct ggc_root_tab gt_pch_rs_gt_gimple_expr_h[];
extern const struct ggc_root_tab gt_pch_rs_gtype_desc_cc[];
extern const struct ggc_root_tab gt_pch_rs_gtype_algol68_h[];
EXPORTED_CONST struct ggc_root_tab * const gt_pch_scalar_rtab[] = {
  gt_pch_rs_gt_alias_h,
  gt_pch_rs_gt_dwarf2asm_h,
  gt_pch_rs_gt_dwarf2cfi_h,
  gt_pch_rs_gt_dwarf2out_h,
  gt_pch_rs_gt_tree_vect_generic_h,
  gt_pch_rs_gt_emit_rtl_h,
  gt_pch_rs_gt_function_h,
  gt_pch_rs_gt_except_h,
  gt_pch_rs_gt_tree_h,
  gt_pch_rs_gt_varasm_h,
  gt_pch_rs_gt_gimple_expr_h,
  gt_pch_rs_gtype_desc_cc,
  gt_pch_rs_gtype_algol68_h,
  NULL
};
