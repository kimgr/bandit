#ifndef BANDIT_SPECS_FAKE_REPORTER_H
#define BANDIT_SPECS_FAKE_REPORTER_H

namespace bandit { namespace fakes {
  struct fake_reporter : 
    public bandit::reporter, 
    public bandit::specs::logging_fake
  {
    fake_reporter() : test_run_status_(true)
    {}

    void test_run_starting()
    {
      log("test_run_starting");
    }

    void test_run_complete()
    {
      log("test_run_complete");
    }

    void context_starting(const char* desc)
    {
      log("context_starting: ", desc);
    }

    void context_ended(const char* desc)
    {
      log("context_ended: ", desc);
    }

    void test_run_error(const char* desc, const struct test_run_error& err)
    {
      log("test_run_error: ", desc, " (", err.what(), ")");
    }

    void it_starting(const char* desc)
    {
      log("it_starting: ", desc);
    }

    void it_succeeded(const char* desc)
    {
      log("it_succeeded: ", desc);
    }

    void it_failed(const char* desc, const assertion_exception& ex)
    {
      log("it_failed: ", desc, " (" , ex.what(), ")");
    }

    void it_unknown_error(const char* desc)
    {
      log("it_unknown_error: ", desc);
    }

    bool did_we_pass() const
    {
      return test_run_status_;
    }

    void set_test_run_status(bool status)
    {
      test_run_status_ = status;
    }

    private:
    bool test_run_status_;
  };
  typedef unique_ptr<fake_reporter> fake_reporter_ptr;
}}

#endif
