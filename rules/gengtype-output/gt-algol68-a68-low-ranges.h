/* Type information for algol68/a68-low-ranges.cc.
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
gt_ggc_mx_range (void *x_p)
{
  struct range * const x = (struct range *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      gt_ggc_m_9tree_node ((*x).names);
      gt_ggc_m_9tree_node ((*x).decl_exprs);
      gt_ggc_m_9tree_node ((*x).context);
      gt_ggc_m_5range ((*x).next);
      gt_ggc_m_9tree_node ((*x).stmt_list);
      gt_ggc_m_9tree_node ((*x).blocks);
      gt_ggc_m_6MOID_T ((*x).mode);
      gt_ggc_m_9tree_node ((*x).fndecl);
      gt_ggc_m_9tree_node ((*x).clause_result_decl);
      gt_ggc_m_9tree_node ((*x).clause_exit_label_decl);
      gt_ggc_m_9tree_node ((*x).clause_stack_save_decl);
    }
}

void
gt_pch_nx_range (void *x_p)
{
  struct range * const x = (struct range *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_5range))
    {
      gt_pch_n_9tree_node ((*x).names);
      gt_pch_n_9tree_node ((*x).decl_exprs);
      gt_pch_n_9tree_node ((*x).context);
      gt_pch_n_5range ((*x).next);
      gt_pch_n_9tree_node ((*x).stmt_list);
      gt_pch_n_9tree_node ((*x).blocks);
      gt_pch_n_6MOID_T ((*x).mode);
      gt_pch_n_9tree_node ((*x).fndecl);
      gt_pch_n_9tree_node ((*x).clause_result_decl);
      gt_pch_n_9tree_node ((*x).clause_exit_label_decl);
      gt_pch_n_9tree_node ((*x).clause_stack_save_decl);
    }
}

void
gt_pch_p_5range (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct range * x ATTRIBUTE_UNUSED = (struct range *)x_p;
  if ((void *)(x) == this_obj)
    op (&((*x).names), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).decl_exprs), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).context), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).next), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).stmt_list), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).blocks), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).mode), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).fndecl), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).clause_result_decl), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).clause_exit_label_decl), NULL, cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).clause_stack_save_decl), NULL, cookie);
}

/* GC roots.  */

EXPORTED_CONST struct ggc_root_tab gt_ggc_r_gt_algol68_a68_low_ranges_h[] = {
  {
    &current_range,
    1,
    sizeof (current_range),
    &gt_ggc_mx_range,
    &gt_pch_nx_range
  },
  {
    &global_range,
    1,
    sizeof (global_range),
    &gt_ggc_mx_range,
    &gt_pch_nx_range
  },
  LAST_GGC_ROOT_TAB
};

