/* Type information for cp/contracts.cc.
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
gt_ggc_mx_hash_map_tree_contract_decl_ (void *x_p)
{
  hash_map<tree,contract_decl> * const x = (hash_map<tree,contract_decl> *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      gt_ggc_mx (x);
    }
}

void
gt_ggc_mx (struct contract_decl& x_r ATTRIBUTE_UNUSED)
{
  struct contract_decl * ATTRIBUTE_UNUSED x = &x_r;
  gt_ggc_m_9tree_node ((*x).contract_specifiers);
}

void
gt_pch_nx_hash_map_tree_contract_decl_ (void *x_p)
{
  hash_map<tree,contract_decl> * const x = (hash_map<tree,contract_decl> *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_28hash_map_tree_contract_decl_))
    {
      gt_pch_nx (x);
    }
}

void
gt_pch_nx (struct contract_decl& x_r ATTRIBUTE_UNUSED)
{
  struct contract_decl * ATTRIBUTE_UNUSED x = &x_r;
  gt_pch_n_9tree_node ((*x).contract_specifiers);
}

void
gt_pch_p_28hash_map_tree_contract_decl_ (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct hash_map<tree,contract_decl> * x ATTRIBUTE_UNUSED = (struct hash_map<tree,contract_decl> *)x_p;
  if ((void *)(x) == this_obj)
    gt_pch_nx (&((*x)), op, cookie);
}

void
gt_pch_nx (struct contract_decl* x ATTRIBUTE_UNUSED,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
    op (&((*x).contract_specifiers), NULL, cookie);
}

/* GC roots.  */

EXPORTED_CONST struct ggc_root_tab gt_ggc_r_gt_cp_contracts_h[] = {
  {
    &contracts_source_location_impl_type,
    1,
    sizeof (contracts_source_location_impl_type),
    &gt_ggc_mx_tree_node,
    &gt_pch_nx_tree_node
  },
  {
    &tu_terminate_wrapper,
    1,
    sizeof (tu_terminate_wrapper),
    &gt_ggc_mx_tree_node,
    &gt_pch_nx_tree_node
  },
  {
    &tu_has_violation_exception,
    1,
    sizeof (tu_has_violation_exception),
    &gt_ggc_mx_tree_node,
    &gt_pch_nx_tree_node
  },
  {
    &tu_has_violation,
    1,
    sizeof (tu_has_violation),
    &gt_ggc_mx_tree_node,
    &gt_pch_nx_tree_node
  },
  {
    &decl_for_wrapper,
    1,
    sizeof (decl_for_wrapper),
    &gt_ggc_mx_hash_map_tree_tree_,
    &gt_pch_nx_hash_map_tree_tree_
  },
  {
    &decl_wrapper_fn,
    1,
    sizeof (decl_wrapper_fn),
    &gt_ggc_mx_hash_map_tree_tree_,
    &gt_pch_nx_hash_map_tree_tree_
  },
  {
    &orig_from_outlined,
    1,
    sizeof (orig_from_outlined),
    &gt_ggc_mx_hash_map_tree_tree_,
    &gt_pch_nx_hash_map_tree_tree_
  },
  {
    &decl_post_fn,
    1,
    sizeof (decl_post_fn),
    &gt_ggc_mx_hash_map_tree_tree_,
    &gt_pch_nx_hash_map_tree_tree_
  },
  {
    &decl_pre_fn,
    1,
    sizeof (decl_pre_fn),
    &gt_ggc_mx_hash_map_tree_tree_,
    &gt_pch_nx_hash_map_tree_tree_
  },
  {
    &contract_decl_map,
    1,
    sizeof (contract_decl_map),
    &gt_ggc_mx_hash_map_tree_contract_decl_,
    &gt_pch_nx_hash_map_tree_contract_decl_
  },
  LAST_GGC_ROOT_TAB
};

