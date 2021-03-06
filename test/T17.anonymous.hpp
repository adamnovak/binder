// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/test/T17.anonymous.hpp
/// @brief  Binder self-test file. Bindings of classes/functions in anonymous namespace
/// @author Sergey Lyskov

#pragma once

namespace {
void foo_not_binded() {}

struct S_not_binded {};
}


void foo() {}

struct S {};
