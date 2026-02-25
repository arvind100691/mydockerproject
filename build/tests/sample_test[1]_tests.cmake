add_test([=[Sanity.OnePlusOne]=]  /workspaces/mydockerproject/build/tests/sample_test [==[--gtest_filter=Sanity.OnePlusOne]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Sanity.OnePlusOne]=]  PROPERTIES WORKING_DIRECTORY /workspaces/mydockerproject/build/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  sample_test_TESTS Sanity.OnePlusOne)
