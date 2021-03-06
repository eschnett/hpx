// Copyright (c) 2007-2013 Hartmut Kaiser
// Copyright (c) 2012-2013 Thomas Heller
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// This file has been automatically generated using the Boost.Wave tool.
// Do not edit manually.


namespace hpx { namespace actions
{
    
    
    template <
        typename Result,
        typename T0,
        Result (*F)(T0), typename Derived>
    class plain_base_result_action1
      : public action<
            components::server::plain_function<Derived>,
            Result,
            hpx::util::tuple<typename util::decay<T0>::type>,
            Derived>
    {
    public:
        typedef Result result_type;
        typedef typename detail::remote_action_result<Result>::type
            remote_result_type;
        typedef hpx::util::tuple<
            typename util::decay<T0>::type> arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static Result
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_result_action" << 1
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            return F(util::get< 0>(boost::forward<Arguments>( args)));
        }
    };
    
    
    template <
        typename Result, typename T0,
        Result (*F)(T0),
        typename Derived = detail::this_type>
    struct plain_result_action1
      : plain_base_result_action1<Result,
          T0, F,
          typename detail::action_type<
              plain_result_action1<
                  Result, T0, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_result_action1, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename Result, typename T0,
        Result (*F)(T0), typename Derived>
    struct make_action<Result (*)(T0), F, Derived, boost::mpl::false_>
      : plain_result_action1<
            Result, T0, F, Derived>
    {
        typedef plain_result_action1<
            Result, T0, F, Derived
        > type;
    };
    
    
    template <
        typename Result, typename T0,
        Result (*F)(T0),
        typename Derived = detail::this_type>
    struct plain_direct_result_action1
      : plain_base_result_action1<Result,
          T0, F,
          typename detail::action_type<
              plain_direct_result_action1<
                  Result, T0, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_direct_result_action1, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename Result, typename T0,
        Result (*F)(T0), typename Derived>
    struct make_action<Result (*)(T0), F, Derived, boost::mpl::true_>
      : plain_direct_result_action1<
            Result, T0, F, Derived>
    {
        typedef plain_direct_result_action1<
            Result, T0, F, Derived
        > type;
    };
    
    
    template <
        typename T0,
        void (*F)(T0), typename Derived>
    class plain_base_action1
      : public action<
            components::server::plain_function<Derived>,
            util::unused_type,
            hpx::util::tuple<typename util::decay<T0>::type>,
            Derived>
    {
    public:
        typedef util::unused_type result_type;
        typedef util::unused_type remote_result_type;
        typedef
            hpx::util::tuple<typename util::decay<T0>::type>
        arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function_void(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static util::unused_type
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_action" << 1
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            F(util::get< 0>(boost::forward<Arguments>( args)));
            return util::unused;
        }
    };
    
    template <
        typename T0,
        void (*F)(T0),
        typename Derived = detail::this_type>
    struct plain_action1
      : plain_base_action1<
            T0, F,
            typename detail::action_type<
                plain_action1<
                    T0, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_action1, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename T0,
        void (*F)(T0), typename Derived>
    struct make_action<void (*)(T0), F, Derived, boost::mpl::false_>
      : plain_action1<
            T0, F, Derived>
    {
        typedef plain_action1<
            T0, F, Derived
        > type;
    };
    
    template <
        typename T0,
        void (*F)(T0),
        typename Derived = detail::this_type>
    struct plain_direct_action1
      : plain_base_action1<
            T0, F,
            typename detail::action_type<
                plain_direct_action1<
                    T0, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_direct_action1, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename T0,
        void (*F)(T0), typename Derived>
    struct make_action<void (*)(T0), F, Derived, boost::mpl::true_>
      : plain_direct_action1<
            T0, F, Derived>
    {
        typedef plain_direct_action1<
            T0, F, Derived
        > type;
    };
    
    
    template <
        typename T0,
        void (*F)(T0), typename Derived>
    struct plain_result_action1<
                void, T0, F, Derived>
      : plain_action1<
            T0, F, Derived>
    {};
}}
namespace hpx { namespace traits
{
    template <typename Arg0,
        void (*F)(Arg0), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_action1<
                    Arg0, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename Arg0,
        void (*F)(Arg0), typename Derived,
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_action1<
                    Arg0, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0,
        R(*F)(Arg0), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_result_action1<
                    R, Arg0, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0,
        R(*F)(Arg0), typename Derived, typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_result_action1<
                    R, Arg0, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
}}
namespace hpx { namespace actions
{
    
    
    template <
        typename Result,
        typename T0 , typename T1,
        Result (*F)(T0 , T1), typename Derived>
    class plain_base_result_action2
      : public action<
            components::server::plain_function<Derived>,
            Result,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type>,
            Derived>
    {
    public:
        typedef Result result_type;
        typedef typename detail::remote_action_result<Result>::type
            remote_result_type;
        typedef hpx::util::tuple<
            typename util::decay<T0>::type , typename util::decay<T1>::type> arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static Result
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_result_action" << 2
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            return F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)));
        }
    };
    
    
    template <
        typename Result, typename T0 , typename T1,
        Result (*F)(T0 , T1),
        typename Derived = detail::this_type>
    struct plain_result_action2
      : plain_base_result_action2<Result,
          T0 , T1, F,
          typename detail::action_type<
              plain_result_action2<
                  Result, T0 , T1, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_result_action2, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename Result, typename T0 , typename T1,
        Result (*F)(T0 , T1), typename Derived>
    struct make_action<Result (*)(T0 , T1), F, Derived, boost::mpl::false_>
      : plain_result_action2<
            Result, T0 , T1, F, Derived>
    {
        typedef plain_result_action2<
            Result, T0 , T1, F, Derived
        > type;
    };
    
    
    template <
        typename Result, typename T0 , typename T1,
        Result (*F)(T0 , T1),
        typename Derived = detail::this_type>
    struct plain_direct_result_action2
      : plain_base_result_action2<Result,
          T0 , T1, F,
          typename detail::action_type<
              plain_direct_result_action2<
                  Result, T0 , T1, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_direct_result_action2, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename Result, typename T0 , typename T1,
        Result (*F)(T0 , T1), typename Derived>
    struct make_action<Result (*)(T0 , T1), F, Derived, boost::mpl::true_>
      : plain_direct_result_action2<
            Result, T0 , T1, F, Derived>
    {
        typedef plain_direct_result_action2<
            Result, T0 , T1, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1,
        void (*F)(T0 , T1), typename Derived>
    class plain_base_action2
      : public action<
            components::server::plain_function<Derived>,
            util::unused_type,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type>,
            Derived>
    {
    public:
        typedef util::unused_type result_type;
        typedef util::unused_type remote_result_type;
        typedef
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type>
        arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function_void(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static util::unused_type
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_action" << 2
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)));
            return util::unused;
        }
    };
    
    template <
        typename T0 , typename T1,
        void (*F)(T0 , T1),
        typename Derived = detail::this_type>
    struct plain_action2
      : plain_base_action2<
            T0 , T1, F,
            typename detail::action_type<
                plain_action2<
                    T0 , T1, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_action2, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename T0 , typename T1,
        void (*F)(T0 , T1), typename Derived>
    struct make_action<void (*)(T0 , T1), F, Derived, boost::mpl::false_>
      : plain_action2<
            T0 , T1, F, Derived>
    {
        typedef plain_action2<
            T0 , T1, F, Derived
        > type;
    };
    
    template <
        typename T0 , typename T1,
        void (*F)(T0 , T1),
        typename Derived = detail::this_type>
    struct plain_direct_action2
      : plain_base_action2<
            T0 , T1, F,
            typename detail::action_type<
                plain_direct_action2<
                    T0 , T1, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_direct_action2, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename T0 , typename T1,
        void (*F)(T0 , T1), typename Derived>
    struct make_action<void (*)(T0 , T1), F, Derived, boost::mpl::true_>
      : plain_direct_action2<
            T0 , T1, F, Derived>
    {
        typedef plain_direct_action2<
            T0 , T1, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1,
        void (*F)(T0 , T1), typename Derived>
    struct plain_result_action2<
                void, T0 , T1, F, Derived>
      : plain_action2<
            T0 , T1, F, Derived>
    {};
}}
namespace hpx { namespace traits
{
    template <typename Arg0 , typename Arg1,
        void (*F)(Arg0 , Arg1), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_action2<
                    Arg0 , Arg1, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename Arg0 , typename Arg1,
        void (*F)(Arg0 , Arg1), typename Derived,
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_action2<
                    Arg0 , Arg1, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1,
        R(*F)(Arg0 , Arg1), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_result_action2<
                    R, Arg0 , Arg1, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1,
        R(*F)(Arg0 , Arg1), typename Derived, typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_result_action2<
                    R, Arg0 , Arg1, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
}}
namespace hpx { namespace actions
{
    
    
    template <
        typename Result,
        typename T0 , typename T1 , typename T2,
        Result (*F)(T0 , T1 , T2), typename Derived>
    class plain_base_result_action3
      : public action<
            components::server::plain_function<Derived>,
            Result,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type>,
            Derived>
    {
    public:
        typedef Result result_type;
        typedef typename detail::remote_action_result<Result>::type
            remote_result_type;
        typedef hpx::util::tuple<
            typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type> arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static Result
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_result_action" << 3
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            return F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)));
        }
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2,
        Result (*F)(T0 , T1 , T2),
        typename Derived = detail::this_type>
    struct plain_result_action3
      : plain_base_result_action3<Result,
          T0 , T1 , T2, F,
          typename detail::action_type<
              plain_result_action3<
                  Result, T0 , T1 , T2, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_result_action3, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename Result, typename T0 , typename T1 , typename T2,
        Result (*F)(T0 , T1 , T2), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2), F, Derived, boost::mpl::false_>
      : plain_result_action3<
            Result, T0 , T1 , T2, F, Derived>
    {
        typedef plain_result_action3<
            Result, T0 , T1 , T2, F, Derived
        > type;
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2,
        Result (*F)(T0 , T1 , T2),
        typename Derived = detail::this_type>
    struct plain_direct_result_action3
      : plain_base_result_action3<Result,
          T0 , T1 , T2, F,
          typename detail::action_type<
              plain_direct_result_action3<
                  Result, T0 , T1 , T2, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_direct_result_action3, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename Result, typename T0 , typename T1 , typename T2,
        Result (*F)(T0 , T1 , T2), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2), F, Derived, boost::mpl::true_>
      : plain_direct_result_action3<
            Result, T0 , T1 , T2, F, Derived>
    {
        typedef plain_direct_result_action3<
            Result, T0 , T1 , T2, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2,
        void (*F)(T0 , T1 , T2), typename Derived>
    class plain_base_action3
      : public action<
            components::server::plain_function<Derived>,
            util::unused_type,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type>,
            Derived>
    {
    public:
        typedef util::unused_type result_type;
        typedef util::unused_type remote_result_type;
        typedef
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type>
        arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function_void(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static util::unused_type
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_action" << 3
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)));
            return util::unused;
        }
    };
    
    template <
        typename T0 , typename T1 , typename T2,
        void (*F)(T0 , T1 , T2),
        typename Derived = detail::this_type>
    struct plain_action3
      : plain_base_action3<
            T0 , T1 , T2, F,
            typename detail::action_type<
                plain_action3<
                    T0 , T1 , T2, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_action3, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename T0 , typename T1 , typename T2,
        void (*F)(T0 , T1 , T2), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2), F, Derived, boost::mpl::false_>
      : plain_action3<
            T0 , T1 , T2, F, Derived>
    {
        typedef plain_action3<
            T0 , T1 , T2, F, Derived
        > type;
    };
    
    template <
        typename T0 , typename T1 , typename T2,
        void (*F)(T0 , T1 , T2),
        typename Derived = detail::this_type>
    struct plain_direct_action3
      : plain_base_action3<
            T0 , T1 , T2, F,
            typename detail::action_type<
                plain_direct_action3<
                    T0 , T1 , T2, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_direct_action3, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename T0 , typename T1 , typename T2,
        void (*F)(T0 , T1 , T2), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2), F, Derived, boost::mpl::true_>
      : plain_direct_action3<
            T0 , T1 , T2, F, Derived>
    {
        typedef plain_direct_action3<
            T0 , T1 , T2, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2,
        void (*F)(T0 , T1 , T2), typename Derived>
    struct plain_result_action3<
                void, T0 , T1 , T2, F, Derived>
      : plain_action3<
            T0 , T1 , T2, F, Derived>
    {};
}}
namespace hpx { namespace traits
{
    template <typename Arg0 , typename Arg1 , typename Arg2,
        void (*F)(Arg0 , Arg1 , Arg2), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_action3<
                    Arg0 , Arg1 , Arg2, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename Arg0 , typename Arg1 , typename Arg2,
        void (*F)(Arg0 , Arg1 , Arg2), typename Derived,
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_action3<
                    Arg0 , Arg1 , Arg2, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2,
        R(*F)(Arg0 , Arg1 , Arg2), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_result_action3<
                    R, Arg0 , Arg1 , Arg2, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2,
        R(*F)(Arg0 , Arg1 , Arg2), typename Derived, typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_result_action3<
                    R, Arg0 , Arg1 , Arg2, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
}}
namespace hpx { namespace actions
{
    
    
    template <
        typename Result,
        typename T0 , typename T1 , typename T2 , typename T3,
        Result (*F)(T0 , T1 , T2 , T3), typename Derived>
    class plain_base_result_action4
      : public action<
            components::server::plain_function<Derived>,
            Result,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type>,
            Derived>
    {
    public:
        typedef Result result_type;
        typedef typename detail::remote_action_result<Result>::type
            remote_result_type;
        typedef hpx::util::tuple<
            typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type> arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static Result
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_result_action" << 4
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            return F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)));
        }
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3,
        Result (*F)(T0 , T1 , T2 , T3),
        typename Derived = detail::this_type>
    struct plain_result_action4
      : plain_base_result_action4<Result,
          T0 , T1 , T2 , T3, F,
          typename detail::action_type<
              plain_result_action4<
                  Result, T0 , T1 , T2 , T3, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_result_action4, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3,
        Result (*F)(T0 , T1 , T2 , T3), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3), F, Derived, boost::mpl::false_>
      : plain_result_action4<
            Result, T0 , T1 , T2 , T3, F, Derived>
    {
        typedef plain_result_action4<
            Result, T0 , T1 , T2 , T3, F, Derived
        > type;
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3,
        Result (*F)(T0 , T1 , T2 , T3),
        typename Derived = detail::this_type>
    struct plain_direct_result_action4
      : plain_base_result_action4<Result,
          T0 , T1 , T2 , T3, F,
          typename detail::action_type<
              plain_direct_result_action4<
                  Result, T0 , T1 , T2 , T3, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_direct_result_action4, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3,
        Result (*F)(T0 , T1 , T2 , T3), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3), F, Derived, boost::mpl::true_>
      : plain_direct_result_action4<
            Result, T0 , T1 , T2 , T3, F, Derived>
    {
        typedef plain_direct_result_action4<
            Result, T0 , T1 , T2 , T3, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3,
        void (*F)(T0 , T1 , T2 , T3), typename Derived>
    class plain_base_action4
      : public action<
            components::server::plain_function<Derived>,
            util::unused_type,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type>,
            Derived>
    {
    public:
        typedef util::unused_type result_type;
        typedef util::unused_type remote_result_type;
        typedef
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type>
        arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function_void(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static util::unused_type
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_action" << 4
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)));
            return util::unused;
        }
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3,
        void (*F)(T0 , T1 , T2 , T3),
        typename Derived = detail::this_type>
    struct plain_action4
      : plain_base_action4<
            T0 , T1 , T2 , T3, F,
            typename detail::action_type<
                plain_action4<
                    T0 , T1 , T2 , T3, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_action4, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename T0 , typename T1 , typename T2 , typename T3,
        void (*F)(T0 , T1 , T2 , T3), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3), F, Derived, boost::mpl::false_>
      : plain_action4<
            T0 , T1 , T2 , T3, F, Derived>
    {
        typedef plain_action4<
            T0 , T1 , T2 , T3, F, Derived
        > type;
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3,
        void (*F)(T0 , T1 , T2 , T3),
        typename Derived = detail::this_type>
    struct plain_direct_action4
      : plain_base_action4<
            T0 , T1 , T2 , T3, F,
            typename detail::action_type<
                plain_direct_action4<
                    T0 , T1 , T2 , T3, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_direct_action4, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename T0 , typename T1 , typename T2 , typename T3,
        void (*F)(T0 , T1 , T2 , T3), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3), F, Derived, boost::mpl::true_>
      : plain_direct_action4<
            T0 , T1 , T2 , T3, F, Derived>
    {
        typedef plain_direct_action4<
            T0 , T1 , T2 , T3, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3,
        void (*F)(T0 , T1 , T2 , T3), typename Derived>
    struct plain_result_action4<
                void, T0 , T1 , T2 , T3, F, Derived>
      : plain_action4<
            T0 , T1 , T2 , T3, F, Derived>
    {};
}}
namespace hpx { namespace traits
{
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_action4<
                    Arg0 , Arg1 , Arg2 , Arg3, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3), typename Derived,
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_action4<
                    Arg0 , Arg1 , Arg2 , Arg3, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_result_action4<
                    R, Arg0 , Arg1 , Arg2 , Arg3, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3), typename Derived, typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_result_action4<
                    R, Arg0 , Arg1 , Arg2 , Arg3, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
}}
namespace hpx { namespace actions
{
    
    
    template <
        typename Result,
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4,
        Result (*F)(T0 , T1 , T2 , T3 , T4), typename Derived>
    class plain_base_result_action5
      : public action<
            components::server::plain_function<Derived>,
            Result,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type>,
            Derived>
    {
    public:
        typedef Result result_type;
        typedef typename detail::remote_action_result<Result>::type
            remote_result_type;
        typedef hpx::util::tuple<
            typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type> arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static Result
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_result_action" << 5
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            return F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)));
        }
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4,
        Result (*F)(T0 , T1 , T2 , T3 , T4),
        typename Derived = detail::this_type>
    struct plain_result_action5
      : plain_base_result_action5<Result,
          T0 , T1 , T2 , T3 , T4, F,
          typename detail::action_type<
              plain_result_action5<
                  Result, T0 , T1 , T2 , T3 , T4, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_result_action5, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4,
        Result (*F)(T0 , T1 , T2 , T3 , T4), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4), F, Derived, boost::mpl::false_>
      : plain_result_action5<
            Result, T0 , T1 , T2 , T3 , T4, F, Derived>
    {
        typedef plain_result_action5<
            Result, T0 , T1 , T2 , T3 , T4, F, Derived
        > type;
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4,
        Result (*F)(T0 , T1 , T2 , T3 , T4),
        typename Derived = detail::this_type>
    struct plain_direct_result_action5
      : plain_base_result_action5<Result,
          T0 , T1 , T2 , T3 , T4, F,
          typename detail::action_type<
              plain_direct_result_action5<
                  Result, T0 , T1 , T2 , T3 , T4, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_direct_result_action5, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4,
        Result (*F)(T0 , T1 , T2 , T3 , T4), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4), F, Derived, boost::mpl::true_>
      : plain_direct_result_action5<
            Result, T0 , T1 , T2 , T3 , T4, F, Derived>
    {
        typedef plain_direct_result_action5<
            Result, T0 , T1 , T2 , T3 , T4, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4,
        void (*F)(T0 , T1 , T2 , T3 , T4), typename Derived>
    class plain_base_action5
      : public action<
            components::server::plain_function<Derived>,
            util::unused_type,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type>,
            Derived>
    {
    public:
        typedef util::unused_type result_type;
        typedef util::unused_type remote_result_type;
        typedef
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type>
        arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function_void(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static util::unused_type
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_action" << 5
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)));
            return util::unused;
        }
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4,
        void (*F)(T0 , T1 , T2 , T3 , T4),
        typename Derived = detail::this_type>
    struct plain_action5
      : plain_base_action5<
            T0 , T1 , T2 , T3 , T4, F,
            typename detail::action_type<
                plain_action5<
                    T0 , T1 , T2 , T3 , T4, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_action5, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4,
        void (*F)(T0 , T1 , T2 , T3 , T4), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4), F, Derived, boost::mpl::false_>
      : plain_action5<
            T0 , T1 , T2 , T3 , T4, F, Derived>
    {
        typedef plain_action5<
            T0 , T1 , T2 , T3 , T4, F, Derived
        > type;
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4,
        void (*F)(T0 , T1 , T2 , T3 , T4),
        typename Derived = detail::this_type>
    struct plain_direct_action5
      : plain_base_action5<
            T0 , T1 , T2 , T3 , T4, F,
            typename detail::action_type<
                plain_direct_action5<
                    T0 , T1 , T2 , T3 , T4, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_direct_action5, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4,
        void (*F)(T0 , T1 , T2 , T3 , T4), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4), F, Derived, boost::mpl::true_>
      : plain_direct_action5<
            T0 , T1 , T2 , T3 , T4, F, Derived>
    {
        typedef plain_direct_action5<
            T0 , T1 , T2 , T3 , T4, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4,
        void (*F)(T0 , T1 , T2 , T3 , T4), typename Derived>
    struct plain_result_action5<
                void, T0 , T1 , T2 , T3 , T4, F, Derived>
      : plain_action5<
            T0 , T1 , T2 , T3 , T4, F, Derived>
    {};
}}
namespace hpx { namespace traits
{
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_action5<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4), typename Derived,
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_action5<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_result_action5<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4), typename Derived, typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_result_action5<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
}}
namespace hpx { namespace actions
{
    
    
    template <
        typename Result,
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5), typename Derived>
    class plain_base_result_action6
      : public action<
            components::server::plain_function<Derived>,
            Result,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type>,
            Derived>
    {
    public:
        typedef Result result_type;
        typedef typename detail::remote_action_result<Result>::type
            remote_result_type;
        typedef hpx::util::tuple<
            typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type> arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4 , BOOST_FWD_REF(Arg5) arg5) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4) , boost::move(arg5));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static Result
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_result_action" << 6
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            return F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)));
        }
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5),
        typename Derived = detail::this_type>
    struct plain_result_action6
      : plain_base_result_action6<Result,
          T0 , T1 , T2 , T3 , T4 , T5, F,
          typename detail::action_type<
              plain_result_action6<
                  Result, T0 , T1 , T2 , T3 , T4 , T5, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_result_action6, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4 , T5), F, Derived, boost::mpl::false_>
      : plain_result_action6<
            Result, T0 , T1 , T2 , T3 , T4 , T5, F, Derived>
    {
        typedef plain_result_action6<
            Result, T0 , T1 , T2 , T3 , T4 , T5, F, Derived
        > type;
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5),
        typename Derived = detail::this_type>
    struct plain_direct_result_action6
      : plain_base_result_action6<Result,
          T0 , T1 , T2 , T3 , T4 , T5, F,
          typename detail::action_type<
              plain_direct_result_action6<
                  Result, T0 , T1 , T2 , T3 , T4 , T5, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_direct_result_action6, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4 , T5), F, Derived, boost::mpl::true_>
      : plain_direct_result_action6<
            Result, T0 , T1 , T2 , T3 , T4 , T5, F, Derived>
    {
        typedef plain_direct_result_action6<
            Result, T0 , T1 , T2 , T3 , T4 , T5, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5), typename Derived>
    class plain_base_action6
      : public action<
            components::server::plain_function<Derived>,
            util::unused_type,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type>,
            Derived>
    {
    public:
        typedef util::unused_type result_type;
        typedef util::unused_type remote_result_type;
        typedef
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type>
        arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4 , BOOST_FWD_REF(Arg5) arg5) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4) , boost::move(arg5));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function_void(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static util::unused_type
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_action" << 6
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)));
            return util::unused;
        }
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5),
        typename Derived = detail::this_type>
    struct plain_action6
      : plain_base_action6<
            T0 , T1 , T2 , T3 , T4 , T5, F,
            typename detail::action_type<
                plain_action6<
                    T0 , T1 , T2 , T3 , T4 , T5, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_action6, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4 , T5), F, Derived, boost::mpl::false_>
      : plain_action6<
            T0 , T1 , T2 , T3 , T4 , T5, F, Derived>
    {
        typedef plain_action6<
            T0 , T1 , T2 , T3 , T4 , T5, F, Derived
        > type;
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5),
        typename Derived = detail::this_type>
    struct plain_direct_action6
      : plain_base_action6<
            T0 , T1 , T2 , T3 , T4 , T5, F,
            typename detail::action_type<
                plain_direct_action6<
                    T0 , T1 , T2 , T3 , T4 , T5, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_direct_action6, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4 , T5), F, Derived, boost::mpl::true_>
      : plain_direct_action6<
            T0 , T1 , T2 , T3 , T4 , T5, F, Derived>
    {
        typedef plain_direct_action6<
            T0 , T1 , T2 , T3 , T4 , T5, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5), typename Derived>
    struct plain_result_action6<
                void, T0 , T1 , T2 , T3 , T4 , T5, F, Derived>
      : plain_action6<
            T0 , T1 , T2 , T3 , T4 , T5, F, Derived>
    {};
}}
namespace hpx { namespace traits
{
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_action6<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5), typename Derived,
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_action6<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_result_action6<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5), typename Derived, typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_result_action6<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
}}
namespace hpx { namespace actions
{
    
    
    template <
        typename Result,
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6), typename Derived>
    class plain_base_result_action7
      : public action<
            components::server::plain_function<Derived>,
            Result,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type>,
            Derived>
    {
    public:
        typedef Result result_type;
        typedef typename detail::remote_action_result<Result>::type
            remote_result_type;
        typedef hpx::util::tuple<
            typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type> arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4 , BOOST_FWD_REF(Arg5) arg5 , BOOST_FWD_REF(Arg6) arg6) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4) , boost::move(arg5) , boost::move(arg6));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static Result
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_result_action" << 7
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            return F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)));
        }
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6),
        typename Derived = detail::this_type>
    struct plain_result_action7
      : plain_base_result_action7<Result,
          T0 , T1 , T2 , T3 , T4 , T5 , T6, F,
          typename detail::action_type<
              plain_result_action7<
                  Result, T0 , T1 , T2 , T3 , T4 , T5 , T6, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_result_action7, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6), F, Derived, boost::mpl::false_>
      : plain_result_action7<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6, F, Derived>
    {
        typedef plain_result_action7<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6, F, Derived
        > type;
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6),
        typename Derived = detail::this_type>
    struct plain_direct_result_action7
      : plain_base_result_action7<Result,
          T0 , T1 , T2 , T3 , T4 , T5 , T6, F,
          typename detail::action_type<
              plain_direct_result_action7<
                  Result, T0 , T1 , T2 , T3 , T4 , T5 , T6, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_direct_result_action7, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6), F, Derived, boost::mpl::true_>
      : plain_direct_result_action7<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6, F, Derived>
    {
        typedef plain_direct_result_action7<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6), typename Derived>
    class plain_base_action7
      : public action<
            components::server::plain_function<Derived>,
            util::unused_type,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type>,
            Derived>
    {
    public:
        typedef util::unused_type result_type;
        typedef util::unused_type remote_result_type;
        typedef
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type>
        arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4 , BOOST_FWD_REF(Arg5) arg5 , BOOST_FWD_REF(Arg6) arg6) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4) , boost::move(arg5) , boost::move(arg6));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function_void(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static util::unused_type
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_action" << 7
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)));
            return util::unused;
        }
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6),
        typename Derived = detail::this_type>
    struct plain_action7
      : plain_base_action7<
            T0 , T1 , T2 , T3 , T4 , T5 , T6, F,
            typename detail::action_type<
                plain_action7<
                    T0 , T1 , T2 , T3 , T4 , T5 , T6, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_action7, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6), F, Derived, boost::mpl::false_>
      : plain_action7<
            T0 , T1 , T2 , T3 , T4 , T5 , T6, F, Derived>
    {
        typedef plain_action7<
            T0 , T1 , T2 , T3 , T4 , T5 , T6, F, Derived
        > type;
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6),
        typename Derived = detail::this_type>
    struct plain_direct_action7
      : plain_base_action7<
            T0 , T1 , T2 , T3 , T4 , T5 , T6, F,
            typename detail::action_type<
                plain_direct_action7<
                    T0 , T1 , T2 , T3 , T4 , T5 , T6, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_direct_action7, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6), F, Derived, boost::mpl::true_>
      : plain_direct_action7<
            T0 , T1 , T2 , T3 , T4 , T5 , T6, F, Derived>
    {
        typedef plain_direct_action7<
            T0 , T1 , T2 , T3 , T4 , T5 , T6, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6), typename Derived>
    struct plain_result_action7<
                void, T0 , T1 , T2 , T3 , T4 , T5 , T6, F, Derived>
      : plain_action7<
            T0 , T1 , T2 , T3 , T4 , T5 , T6, F, Derived>
    {};
}}
namespace hpx { namespace traits
{
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_action7<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6), typename Derived,
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_action7<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_result_action7<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6), typename Derived, typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_result_action7<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
}}
namespace hpx { namespace actions
{
    
    
    template <
        typename Result,
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7), typename Derived>
    class plain_base_result_action8
      : public action<
            components::server::plain_function<Derived>,
            Result,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type>,
            Derived>
    {
    public:
        typedef Result result_type;
        typedef typename detail::remote_action_result<Result>::type
            remote_result_type;
        typedef hpx::util::tuple<
            typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type> arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4 , BOOST_FWD_REF(Arg5) arg5 , BOOST_FWD_REF(Arg6) arg6 , BOOST_FWD_REF(Arg7) arg7) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4) , boost::move(arg5) , boost::move(arg6) , boost::move(arg7));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static Result
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_result_action" << 8
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            return F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)));
        }
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7),
        typename Derived = detail::this_type>
    struct plain_result_action8
      : plain_base_result_action8<Result,
          T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7, F,
          typename detail::action_type<
              plain_result_action8<
                  Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_result_action8, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7), F, Derived, boost::mpl::false_>
      : plain_result_action8<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7, F, Derived>
    {
        typedef plain_result_action8<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7, F, Derived
        > type;
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7),
        typename Derived = detail::this_type>
    struct plain_direct_result_action8
      : plain_base_result_action8<Result,
          T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7, F,
          typename detail::action_type<
              plain_direct_result_action8<
                  Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_direct_result_action8, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7), F, Derived, boost::mpl::true_>
      : plain_direct_result_action8<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7, F, Derived>
    {
        typedef plain_direct_result_action8<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7), typename Derived>
    class plain_base_action8
      : public action<
            components::server::plain_function<Derived>,
            util::unused_type,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type>,
            Derived>
    {
    public:
        typedef util::unused_type result_type;
        typedef util::unused_type remote_result_type;
        typedef
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type>
        arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4 , BOOST_FWD_REF(Arg5) arg5 , BOOST_FWD_REF(Arg6) arg6 , BOOST_FWD_REF(Arg7) arg7) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4) , boost::move(arg5) , boost::move(arg6) , boost::move(arg7));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function_void(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static util::unused_type
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_action" << 8
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)));
            return util::unused;
        }
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7),
        typename Derived = detail::this_type>
    struct plain_action8
      : plain_base_action8<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7, F,
            typename detail::action_type<
                plain_action8<
                    T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_action8, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7), F, Derived, boost::mpl::false_>
      : plain_action8<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7, F, Derived>
    {
        typedef plain_action8<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7, F, Derived
        > type;
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7),
        typename Derived = detail::this_type>
    struct plain_direct_action8
      : plain_base_action8<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7, F,
            typename detail::action_type<
                plain_direct_action8<
                    T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_direct_action8, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7), F, Derived, boost::mpl::true_>
      : plain_direct_action8<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7, F, Derived>
    {
        typedef plain_direct_action8<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7), typename Derived>
    struct plain_result_action8<
                void, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7, F, Derived>
      : plain_action8<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7, F, Derived>
    {};
}}
namespace hpx { namespace traits
{
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_action8<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7), typename Derived,
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_action8<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_result_action8<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7), typename Derived, typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_result_action8<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
}}
namespace hpx { namespace actions
{
    
    
    template <
        typename Result,
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8), typename Derived>
    class plain_base_result_action9
      : public action<
            components::server::plain_function<Derived>,
            Result,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type>,
            Derived>
    {
    public:
        typedef Result result_type;
        typedef typename detail::remote_action_result<Result>::type
            remote_result_type;
        typedef hpx::util::tuple<
            typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type> arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4 , BOOST_FWD_REF(Arg5) arg5 , BOOST_FWD_REF(Arg6) arg6 , BOOST_FWD_REF(Arg7) arg7 , BOOST_FWD_REF(Arg8) arg8) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4) , boost::move(arg5) , boost::move(arg6) , boost::move(arg7) , boost::move(arg8));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static Result
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_result_action" << 9
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            return F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)));
        }
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8),
        typename Derived = detail::this_type>
    struct plain_result_action9
      : plain_base_result_action9<Result,
          T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8, F,
          typename detail::action_type<
              plain_result_action9<
                  Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_result_action9, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8), F, Derived, boost::mpl::false_>
      : plain_result_action9<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8, F, Derived>
    {
        typedef plain_result_action9<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8, F, Derived
        > type;
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8),
        typename Derived = detail::this_type>
    struct plain_direct_result_action9
      : plain_base_result_action9<Result,
          T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8, F,
          typename detail::action_type<
              plain_direct_result_action9<
                  Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_direct_result_action9, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8), F, Derived, boost::mpl::true_>
      : plain_direct_result_action9<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8, F, Derived>
    {
        typedef plain_direct_result_action9<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8), typename Derived>
    class plain_base_action9
      : public action<
            components::server::plain_function<Derived>,
            util::unused_type,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type>,
            Derived>
    {
    public:
        typedef util::unused_type result_type;
        typedef util::unused_type remote_result_type;
        typedef
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type>
        arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4 , BOOST_FWD_REF(Arg5) arg5 , BOOST_FWD_REF(Arg6) arg6 , BOOST_FWD_REF(Arg7) arg7 , BOOST_FWD_REF(Arg8) arg8) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4) , boost::move(arg5) , boost::move(arg6) , boost::move(arg7) , boost::move(arg8));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function_void(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static util::unused_type
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_action" << 9
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)));
            return util::unused;
        }
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8),
        typename Derived = detail::this_type>
    struct plain_action9
      : plain_base_action9<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8, F,
            typename detail::action_type<
                plain_action9<
                    T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_action9, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8), F, Derived, boost::mpl::false_>
      : plain_action9<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8, F, Derived>
    {
        typedef plain_action9<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8, F, Derived
        > type;
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8),
        typename Derived = detail::this_type>
    struct plain_direct_action9
      : plain_base_action9<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8, F,
            typename detail::action_type<
                plain_direct_action9<
                    T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_direct_action9, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8), F, Derived, boost::mpl::true_>
      : plain_direct_action9<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8, F, Derived>
    {
        typedef plain_direct_action9<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8), typename Derived>
    struct plain_result_action9<
                void, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8, F, Derived>
      : plain_action9<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8, F, Derived>
    {};
}}
namespace hpx { namespace traits
{
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_action9<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8), typename Derived,
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_action9<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_result_action9<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8), typename Derived, typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_result_action9<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
}}
namespace hpx { namespace actions
{
    
    
    template <
        typename Result,
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9), typename Derived>
    class plain_base_result_action10
      : public action<
            components::server::plain_function<Derived>,
            Result,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type>,
            Derived>
    {
    public:
        typedef Result result_type;
        typedef typename detail::remote_action_result<Result>::type
            remote_result_type;
        typedef hpx::util::tuple<
            typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type> arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4 , BOOST_FWD_REF(Arg5) arg5 , BOOST_FWD_REF(Arg6) arg6 , BOOST_FWD_REF(Arg7) arg7 , BOOST_FWD_REF(Arg8) arg8 , BOOST_FWD_REF(Arg9) arg9) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4) , boost::move(arg5) , boost::move(arg6) , boost::move(arg7) , boost::move(arg8) , boost::move(arg9));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static Result
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_result_action" << 10
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            return F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)));
        }
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9),
        typename Derived = detail::this_type>
    struct plain_result_action10
      : plain_base_result_action10<Result,
          T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9, F,
          typename detail::action_type<
              plain_result_action10<
                  Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_result_action10, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9), F, Derived, boost::mpl::false_>
      : plain_result_action10<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9, F, Derived>
    {
        typedef plain_result_action10<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9, F, Derived
        > type;
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9),
        typename Derived = detail::this_type>
    struct plain_direct_result_action10
      : plain_base_result_action10<Result,
          T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9, F,
          typename detail::action_type<
              plain_direct_result_action10<
                  Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_direct_result_action10, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9), F, Derived, boost::mpl::true_>
      : plain_direct_result_action10<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9, F, Derived>
    {
        typedef plain_direct_result_action10<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9), typename Derived>
    class plain_base_action10
      : public action<
            components::server::plain_function<Derived>,
            util::unused_type,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type>,
            Derived>
    {
    public:
        typedef util::unused_type result_type;
        typedef util::unused_type remote_result_type;
        typedef
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type>
        arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4 , BOOST_FWD_REF(Arg5) arg5 , BOOST_FWD_REF(Arg6) arg6 , BOOST_FWD_REF(Arg7) arg7 , BOOST_FWD_REF(Arg8) arg8 , BOOST_FWD_REF(Arg9) arg9) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4) , boost::move(arg5) , boost::move(arg6) , boost::move(arg7) , boost::move(arg8) , boost::move(arg9));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function_void(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static util::unused_type
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_action" << 10
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)));
            return util::unused;
        }
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9),
        typename Derived = detail::this_type>
    struct plain_action10
      : plain_base_action10<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9, F,
            typename detail::action_type<
                plain_action10<
                    T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_action10, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9), F, Derived, boost::mpl::false_>
      : plain_action10<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9, F, Derived>
    {
        typedef plain_action10<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9, F, Derived
        > type;
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9),
        typename Derived = detail::this_type>
    struct plain_direct_action10
      : plain_base_action10<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9, F,
            typename detail::action_type<
                plain_direct_action10<
                    T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_direct_action10, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9), F, Derived, boost::mpl::true_>
      : plain_direct_action10<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9, F, Derived>
    {
        typedef plain_direct_action10<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9), typename Derived>
    struct plain_result_action10<
                void, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9, F, Derived>
      : plain_action10<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9, F, Derived>
    {};
}}
namespace hpx { namespace traits
{
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_action10<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9), typename Derived,
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_action10<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_result_action10<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9), typename Derived, typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_result_action10<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
}}
namespace hpx { namespace actions
{
    
    
    template <
        typename Result,
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10), typename Derived>
    class plain_base_result_action11
      : public action<
            components::server::plain_function<Derived>,
            Result,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type>,
            Derived>
    {
    public:
        typedef Result result_type;
        typedef typename detail::remote_action_result<Result>::type
            remote_result_type;
        typedef hpx::util::tuple<
            typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type> arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4 , BOOST_FWD_REF(Arg5) arg5 , BOOST_FWD_REF(Arg6) arg6 , BOOST_FWD_REF(Arg7) arg7 , BOOST_FWD_REF(Arg8) arg8 , BOOST_FWD_REF(Arg9) arg9 , BOOST_FWD_REF(Arg10) arg10) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4) , boost::move(arg5) , boost::move(arg6) , boost::move(arg7) , boost::move(arg8) , boost::move(arg9) , boost::move(arg10));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static Result
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_result_action" << 11
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            return F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)));
        }
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10),
        typename Derived = detail::this_type>
    struct plain_result_action11
      : plain_base_result_action11<Result,
          T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10, F,
          typename detail::action_type<
              plain_result_action11<
                  Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_result_action11, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10), F, Derived, boost::mpl::false_>
      : plain_result_action11<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10, F, Derived>
    {
        typedef plain_result_action11<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10, F, Derived
        > type;
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10),
        typename Derived = detail::this_type>
    struct plain_direct_result_action11
      : plain_base_result_action11<Result,
          T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10, F,
          typename detail::action_type<
              plain_direct_result_action11<
                  Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_direct_result_action11, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10), F, Derived, boost::mpl::true_>
      : plain_direct_result_action11<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10, F, Derived>
    {
        typedef plain_direct_result_action11<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10), typename Derived>
    class plain_base_action11
      : public action<
            components::server::plain_function<Derived>,
            util::unused_type,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type>,
            Derived>
    {
    public:
        typedef util::unused_type result_type;
        typedef util::unused_type remote_result_type;
        typedef
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type>
        arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4 , BOOST_FWD_REF(Arg5) arg5 , BOOST_FWD_REF(Arg6) arg6 , BOOST_FWD_REF(Arg7) arg7 , BOOST_FWD_REF(Arg8) arg8 , BOOST_FWD_REF(Arg9) arg9 , BOOST_FWD_REF(Arg10) arg10) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4) , boost::move(arg5) , boost::move(arg6) , boost::move(arg7) , boost::move(arg8) , boost::move(arg9) , boost::move(arg10));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function_void(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static util::unused_type
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_action" << 11
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)));
            return util::unused;
        }
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10),
        typename Derived = detail::this_type>
    struct plain_action11
      : plain_base_action11<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10, F,
            typename detail::action_type<
                plain_action11<
                    T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_action11, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10), F, Derived, boost::mpl::false_>
      : plain_action11<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10, F, Derived>
    {
        typedef plain_action11<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10, F, Derived
        > type;
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10),
        typename Derived = detail::this_type>
    struct plain_direct_action11
      : plain_base_action11<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10, F,
            typename detail::action_type<
                plain_direct_action11<
                    T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_direct_action11, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10), F, Derived, boost::mpl::true_>
      : plain_direct_action11<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10, F, Derived>
    {
        typedef plain_direct_action11<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10), typename Derived>
    struct plain_result_action11<
                void, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10, F, Derived>
      : plain_action11<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10, F, Derived>
    {};
}}
namespace hpx { namespace traits
{
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_action11<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10), typename Derived,
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_action11<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_result_action11<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10), typename Derived, typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_result_action11<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
}}
namespace hpx { namespace actions
{
    
    
    template <
        typename Result,
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11), typename Derived>
    class plain_base_result_action12
      : public action<
            components::server::plain_function<Derived>,
            Result,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type>,
            Derived>
    {
    public:
        typedef Result result_type;
        typedef typename detail::remote_action_result<Result>::type
            remote_result_type;
        typedef hpx::util::tuple<
            typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type> arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4 , BOOST_FWD_REF(Arg5) arg5 , BOOST_FWD_REF(Arg6) arg6 , BOOST_FWD_REF(Arg7) arg7 , BOOST_FWD_REF(Arg8) arg8 , BOOST_FWD_REF(Arg9) arg9 , BOOST_FWD_REF(Arg10) arg10 , BOOST_FWD_REF(Arg11) arg11) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4) , boost::move(arg5) , boost::move(arg6) , boost::move(arg7) , boost::move(arg8) , boost::move(arg9) , boost::move(arg10) , boost::move(arg11));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static Result
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_result_action" << 12
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            return F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)));
        }
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11),
        typename Derived = detail::this_type>
    struct plain_result_action12
      : plain_base_result_action12<Result,
          T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11, F,
          typename detail::action_type<
              plain_result_action12<
                  Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_result_action12, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11), F, Derived, boost::mpl::false_>
      : plain_result_action12<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11, F, Derived>
    {
        typedef plain_result_action12<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11, F, Derived
        > type;
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11),
        typename Derived = detail::this_type>
    struct plain_direct_result_action12
      : plain_base_result_action12<Result,
          T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11, F,
          typename detail::action_type<
              plain_direct_result_action12<
                  Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_direct_result_action12, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11), F, Derived, boost::mpl::true_>
      : plain_direct_result_action12<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11, F, Derived>
    {
        typedef plain_direct_result_action12<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11), typename Derived>
    class plain_base_action12
      : public action<
            components::server::plain_function<Derived>,
            util::unused_type,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type>,
            Derived>
    {
    public:
        typedef util::unused_type result_type;
        typedef util::unused_type remote_result_type;
        typedef
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type>
        arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4 , BOOST_FWD_REF(Arg5) arg5 , BOOST_FWD_REF(Arg6) arg6 , BOOST_FWD_REF(Arg7) arg7 , BOOST_FWD_REF(Arg8) arg8 , BOOST_FWD_REF(Arg9) arg9 , BOOST_FWD_REF(Arg10) arg10 , BOOST_FWD_REF(Arg11) arg11) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4) , boost::move(arg5) , boost::move(arg6) , boost::move(arg7) , boost::move(arg8) , boost::move(arg9) , boost::move(arg10) , boost::move(arg11));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function_void(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static util::unused_type
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_action" << 12
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)));
            return util::unused;
        }
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11),
        typename Derived = detail::this_type>
    struct plain_action12
      : plain_base_action12<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11, F,
            typename detail::action_type<
                plain_action12<
                    T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_action12, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11), F, Derived, boost::mpl::false_>
      : plain_action12<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11, F, Derived>
    {
        typedef plain_action12<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11, F, Derived
        > type;
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11),
        typename Derived = detail::this_type>
    struct plain_direct_action12
      : plain_base_action12<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11, F,
            typename detail::action_type<
                plain_direct_action12<
                    T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_direct_action12, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11), F, Derived, boost::mpl::true_>
      : plain_direct_action12<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11, F, Derived>
    {
        typedef plain_direct_action12<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11), typename Derived>
    struct plain_result_action12<
                void, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11, F, Derived>
      : plain_action12<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11, F, Derived>
    {};
}}
namespace hpx { namespace traits
{
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_action12<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11), typename Derived,
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_action12<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_result_action12<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11), typename Derived, typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_result_action12<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
}}
namespace hpx { namespace actions
{
    
    
    template <
        typename Result,
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12), typename Derived>
    class plain_base_result_action13
      : public action<
            components::server::plain_function<Derived>,
            Result,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type>,
            Derived>
    {
    public:
        typedef Result result_type;
        typedef typename detail::remote_action_result<Result>::type
            remote_result_type;
        typedef hpx::util::tuple<
            typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type> arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4 , BOOST_FWD_REF(Arg5) arg5 , BOOST_FWD_REF(Arg6) arg6 , BOOST_FWD_REF(Arg7) arg7 , BOOST_FWD_REF(Arg8) arg8 , BOOST_FWD_REF(Arg9) arg9 , BOOST_FWD_REF(Arg10) arg10 , BOOST_FWD_REF(Arg11) arg11 , BOOST_FWD_REF(Arg12) arg12) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4) , boost::move(arg5) , boost::move(arg6) , boost::move(arg7) , boost::move(arg8) , boost::move(arg9) , boost::move(arg10) , boost::move(arg11) , boost::move(arg12));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static Result
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_result_action" << 13
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            return F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args)));
        }
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12),
        typename Derived = detail::this_type>
    struct plain_result_action13
      : plain_base_result_action13<Result,
          T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12, F,
          typename detail::action_type<
              plain_result_action13<
                  Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_result_action13, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12), F, Derived, boost::mpl::false_>
      : plain_result_action13<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12, F, Derived>
    {
        typedef plain_result_action13<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12, F, Derived
        > type;
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12),
        typename Derived = detail::this_type>
    struct plain_direct_result_action13
      : plain_base_result_action13<Result,
          T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12, F,
          typename detail::action_type<
              plain_direct_result_action13<
                  Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_direct_result_action13, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12), F, Derived, boost::mpl::true_>
      : plain_direct_result_action13<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12, F, Derived>
    {
        typedef plain_direct_result_action13<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12), typename Derived>
    class plain_base_action13
      : public action<
            components::server::plain_function<Derived>,
            util::unused_type,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type>,
            Derived>
    {
    public:
        typedef util::unused_type result_type;
        typedef util::unused_type remote_result_type;
        typedef
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type>
        arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4 , BOOST_FWD_REF(Arg5) arg5 , BOOST_FWD_REF(Arg6) arg6 , BOOST_FWD_REF(Arg7) arg7 , BOOST_FWD_REF(Arg8) arg8 , BOOST_FWD_REF(Arg9) arg9 , BOOST_FWD_REF(Arg10) arg10 , BOOST_FWD_REF(Arg11) arg11 , BOOST_FWD_REF(Arg12) arg12) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4) , boost::move(arg5) , boost::move(arg6) , boost::move(arg7) , boost::move(arg8) , boost::move(arg9) , boost::move(arg10) , boost::move(arg11) , boost::move(arg12));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function_void(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static util::unused_type
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_action" << 13
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args)));
            return util::unused;
        }
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12),
        typename Derived = detail::this_type>
    struct plain_action13
      : plain_base_action13<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12, F,
            typename detail::action_type<
                plain_action13<
                    T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_action13, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12), F, Derived, boost::mpl::false_>
      : plain_action13<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12, F, Derived>
    {
        typedef plain_action13<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12, F, Derived
        > type;
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12),
        typename Derived = detail::this_type>
    struct plain_direct_action13
      : plain_base_action13<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12, F,
            typename detail::action_type<
                plain_direct_action13<
                    T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_direct_action13, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12), F, Derived, boost::mpl::true_>
      : plain_direct_action13<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12, F, Derived>
    {
        typedef plain_direct_action13<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12), typename Derived>
    struct plain_result_action13<
                void, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12, F, Derived>
      : plain_action13<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12, F, Derived>
    {};
}}
namespace hpx { namespace traits
{
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_action13<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12), typename Derived,
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_action13<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_result_action13<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12), typename Derived, typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_result_action13<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
}}
namespace hpx { namespace actions
{
    
    
    template <
        typename Result,
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13), typename Derived>
    class plain_base_result_action14
      : public action<
            components::server::plain_function<Derived>,
            Result,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type , typename util::decay<T13>::type>,
            Derived>
    {
    public:
        typedef Result result_type;
        typedef typename detail::remote_action_result<Result>::type
            remote_result_type;
        typedef hpx::util::tuple<
            typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type , typename util::decay<T13>::type> arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4 , BOOST_FWD_REF(Arg5) arg5 , BOOST_FWD_REF(Arg6) arg6 , BOOST_FWD_REF(Arg7) arg7 , BOOST_FWD_REF(Arg8) arg8 , BOOST_FWD_REF(Arg9) arg9 , BOOST_FWD_REF(Arg10) arg10 , BOOST_FWD_REF(Arg11) arg11 , BOOST_FWD_REF(Arg12) arg12 , BOOST_FWD_REF(Arg13) arg13) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4) , boost::move(arg5) , boost::move(arg6) , boost::move(arg7) , boost::move(arg8) , boost::move(arg9) , boost::move(arg10) , boost::move(arg11) , boost::move(arg12) , boost::move(arg13));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args)) , util::get< 13>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static Result
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_result_action" << 14
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            return F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args)) , util::get< 13>(boost::forward<Arguments>( args)));
        }
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13),
        typename Derived = detail::this_type>
    struct plain_result_action14
      : plain_base_result_action14<Result,
          T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13, F,
          typename detail::action_type<
              plain_result_action14<
                  Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_result_action14, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13), F, Derived, boost::mpl::false_>
      : plain_result_action14<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13, F, Derived>
    {
        typedef plain_result_action14<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13, F, Derived
        > type;
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13),
        typename Derived = detail::this_type>
    struct plain_direct_result_action14
      : plain_base_result_action14<Result,
          T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13, F,
          typename detail::action_type<
              plain_direct_result_action14<
                  Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_direct_result_action14, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13), F, Derived, boost::mpl::true_>
      : plain_direct_result_action14<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13, F, Derived>
    {
        typedef plain_direct_result_action14<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13), typename Derived>
    class plain_base_action14
      : public action<
            components::server::plain_function<Derived>,
            util::unused_type,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type , typename util::decay<T13>::type>,
            Derived>
    {
    public:
        typedef util::unused_type result_type;
        typedef util::unused_type remote_result_type;
        typedef
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type , typename util::decay<T13>::type>
        arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4 , BOOST_FWD_REF(Arg5) arg5 , BOOST_FWD_REF(Arg6) arg6 , BOOST_FWD_REF(Arg7) arg7 , BOOST_FWD_REF(Arg8) arg8 , BOOST_FWD_REF(Arg9) arg9 , BOOST_FWD_REF(Arg10) arg10 , BOOST_FWD_REF(Arg11) arg11 , BOOST_FWD_REF(Arg12) arg12 , BOOST_FWD_REF(Arg13) arg13) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4) , boost::move(arg5) , boost::move(arg6) , boost::move(arg7) , boost::move(arg8) , boost::move(arg9) , boost::move(arg10) , boost::move(arg11) , boost::move(arg12) , boost::move(arg13));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args)) , util::get< 13>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function_void(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static util::unused_type
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_action" << 14
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args)) , util::get< 13>(boost::forward<Arguments>( args)));
            return util::unused;
        }
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13),
        typename Derived = detail::this_type>
    struct plain_action14
      : plain_base_action14<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13, F,
            typename detail::action_type<
                plain_action14<
                    T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_action14, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13), F, Derived, boost::mpl::false_>
      : plain_action14<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13, F, Derived>
    {
        typedef plain_action14<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13, F, Derived
        > type;
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13),
        typename Derived = detail::this_type>
    struct plain_direct_action14
      : plain_base_action14<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13, F,
            typename detail::action_type<
                plain_direct_action14<
                    T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_direct_action14, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13), F, Derived, boost::mpl::true_>
      : plain_direct_action14<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13, F, Derived>
    {
        typedef plain_direct_action14<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13), typename Derived>
    struct plain_result_action14<
                void, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13, F, Derived>
      : plain_action14<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13, F, Derived>
    {};
}}
namespace hpx { namespace traits
{
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_action14<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13), typename Derived,
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_action14<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_result_action14<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13), typename Derived, typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_result_action14<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
}}
namespace hpx { namespace actions
{
    
    
    template <
        typename Result,
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14), typename Derived>
    class plain_base_result_action15
      : public action<
            components::server::plain_function<Derived>,
            Result,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type , typename util::decay<T13>::type , typename util::decay<T14>::type>,
            Derived>
    {
    public:
        typedef Result result_type;
        typedef typename detail::remote_action_result<Result>::type
            remote_result_type;
        typedef hpx::util::tuple<
            typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type , typename util::decay<T13>::type , typename util::decay<T14>::type> arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4 , BOOST_FWD_REF(Arg5) arg5 , BOOST_FWD_REF(Arg6) arg6 , BOOST_FWD_REF(Arg7) arg7 , BOOST_FWD_REF(Arg8) arg8 , BOOST_FWD_REF(Arg9) arg9 , BOOST_FWD_REF(Arg10) arg10 , BOOST_FWD_REF(Arg11) arg11 , BOOST_FWD_REF(Arg12) arg12 , BOOST_FWD_REF(Arg13) arg13 , BOOST_FWD_REF(Arg14) arg14) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4) , boost::move(arg5) , boost::move(arg6) , boost::move(arg7) , boost::move(arg8) , boost::move(arg9) , boost::move(arg10) , boost::move(arg11) , boost::move(arg12) , boost::move(arg13) , boost::move(arg14));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args)) , util::get< 13>(boost::forward<Arguments>( args)) , util::get< 14>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static Result
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_result_action" << 15
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            return F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args)) , util::get< 13>(boost::forward<Arguments>( args)) , util::get< 14>(boost::forward<Arguments>( args)));
        }
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14),
        typename Derived = detail::this_type>
    struct plain_result_action15
      : plain_base_result_action15<Result,
          T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14, F,
          typename detail::action_type<
              plain_result_action15<
                  Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_result_action15, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14), F, Derived, boost::mpl::false_>
      : plain_result_action15<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14, F, Derived>
    {
        typedef plain_result_action15<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14, F, Derived
        > type;
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14),
        typename Derived = detail::this_type>
    struct plain_direct_result_action15
      : plain_base_result_action15<Result,
          T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14, F,
          typename detail::action_type<
              plain_direct_result_action15<
                  Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_direct_result_action15, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14), F, Derived, boost::mpl::true_>
      : plain_direct_result_action15<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14, F, Derived>
    {
        typedef plain_direct_result_action15<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14), typename Derived>
    class plain_base_action15
      : public action<
            components::server::plain_function<Derived>,
            util::unused_type,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type , typename util::decay<T13>::type , typename util::decay<T14>::type>,
            Derived>
    {
    public:
        typedef util::unused_type result_type;
        typedef util::unused_type remote_result_type;
        typedef
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type , typename util::decay<T13>::type , typename util::decay<T14>::type>
        arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4 , BOOST_FWD_REF(Arg5) arg5 , BOOST_FWD_REF(Arg6) arg6 , BOOST_FWD_REF(Arg7) arg7 , BOOST_FWD_REF(Arg8) arg8 , BOOST_FWD_REF(Arg9) arg9 , BOOST_FWD_REF(Arg10) arg10 , BOOST_FWD_REF(Arg11) arg11 , BOOST_FWD_REF(Arg12) arg12 , BOOST_FWD_REF(Arg13) arg13 , BOOST_FWD_REF(Arg14) arg14) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4) , boost::move(arg5) , boost::move(arg6) , boost::move(arg7) , boost::move(arg8) , boost::move(arg9) , boost::move(arg10) , boost::move(arg11) , boost::move(arg12) , boost::move(arg13) , boost::move(arg14));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args)) , util::get< 13>(boost::forward<Arguments>( args)) , util::get< 14>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function_void(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static util::unused_type
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_action" << 15
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args)) , util::get< 13>(boost::forward<Arguments>( args)) , util::get< 14>(boost::forward<Arguments>( args)));
            return util::unused;
        }
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14),
        typename Derived = detail::this_type>
    struct plain_action15
      : plain_base_action15<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14, F,
            typename detail::action_type<
                plain_action15<
                    T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_action15, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14), F, Derived, boost::mpl::false_>
      : plain_action15<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14, F, Derived>
    {
        typedef plain_action15<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14, F, Derived
        > type;
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14),
        typename Derived = detail::this_type>
    struct plain_direct_action15
      : plain_base_action15<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14, F,
            typename detail::action_type<
                plain_direct_action15<
                    T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_direct_action15, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14), F, Derived, boost::mpl::true_>
      : plain_direct_action15<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14, F, Derived>
    {
        typedef plain_direct_action15<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14), typename Derived>
    struct plain_result_action15<
                void, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14, F, Derived>
      : plain_action15<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14, F, Derived>
    {};
}}
namespace hpx { namespace traits
{
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_action15<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14), typename Derived,
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_action15<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_result_action15<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14), typename Derived, typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_result_action15<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
}}
namespace hpx { namespace actions
{
    
    
    template <
        typename Result,
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15), typename Derived>
    class plain_base_result_action16
      : public action<
            components::server::plain_function<Derived>,
            Result,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type , typename util::decay<T13>::type , typename util::decay<T14>::type , typename util::decay<T15>::type>,
            Derived>
    {
    public:
        typedef Result result_type;
        typedef typename detail::remote_action_result<Result>::type
            remote_result_type;
        typedef hpx::util::tuple<
            typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type , typename util::decay<T13>::type , typename util::decay<T14>::type , typename util::decay<T15>::type> arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14 , typename Arg15>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4 , BOOST_FWD_REF(Arg5) arg5 , BOOST_FWD_REF(Arg6) arg6 , BOOST_FWD_REF(Arg7) arg7 , BOOST_FWD_REF(Arg8) arg8 , BOOST_FWD_REF(Arg9) arg9 , BOOST_FWD_REF(Arg10) arg10 , BOOST_FWD_REF(Arg11) arg11 , BOOST_FWD_REF(Arg12) arg12 , BOOST_FWD_REF(Arg13) arg13 , BOOST_FWD_REF(Arg14) arg14 , BOOST_FWD_REF(Arg15) arg15) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4) , boost::move(arg5) , boost::move(arg6) , boost::move(arg7) , boost::move(arg8) , boost::move(arg9) , boost::move(arg10) , boost::move(arg11) , boost::move(arg12) , boost::move(arg13) , boost::move(arg14) , boost::move(arg15));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args)) , util::get< 13>(boost::forward<Arguments>( args)) , util::get< 14>(boost::forward<Arguments>( args)) , util::get< 15>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static Result
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_result_action" << 16
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            return F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args)) , util::get< 13>(boost::forward<Arguments>( args)) , util::get< 14>(boost::forward<Arguments>( args)) , util::get< 15>(boost::forward<Arguments>( args)));
        }
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15),
        typename Derived = detail::this_type>
    struct plain_result_action16
      : plain_base_result_action16<Result,
          T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15, F,
          typename detail::action_type<
              plain_result_action16<
                  Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_result_action16, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15), F, Derived, boost::mpl::false_>
      : plain_result_action16<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15, F, Derived>
    {
        typedef plain_result_action16<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15, F, Derived
        > type;
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15),
        typename Derived = detail::this_type>
    struct plain_direct_result_action16
      : plain_base_result_action16<Result,
          T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15, F,
          typename detail::action_type<
              plain_direct_result_action16<
                  Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_direct_result_action16, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15), F, Derived, boost::mpl::true_>
      : plain_direct_result_action16<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15, F, Derived>
    {
        typedef plain_direct_result_action16<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15), typename Derived>
    class plain_base_action16
      : public action<
            components::server::plain_function<Derived>,
            util::unused_type,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type , typename util::decay<T13>::type , typename util::decay<T14>::type , typename util::decay<T15>::type>,
            Derived>
    {
    public:
        typedef util::unused_type result_type;
        typedef util::unused_type remote_result_type;
        typedef
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type , typename util::decay<T13>::type , typename util::decay<T14>::type , typename util::decay<T15>::type>
        arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14 , typename Arg15>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4 , BOOST_FWD_REF(Arg5) arg5 , BOOST_FWD_REF(Arg6) arg6 , BOOST_FWD_REF(Arg7) arg7 , BOOST_FWD_REF(Arg8) arg8 , BOOST_FWD_REF(Arg9) arg9 , BOOST_FWD_REF(Arg10) arg10 , BOOST_FWD_REF(Arg11) arg11 , BOOST_FWD_REF(Arg12) arg12 , BOOST_FWD_REF(Arg13) arg13 , BOOST_FWD_REF(Arg14) arg14 , BOOST_FWD_REF(Arg15) arg15) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4) , boost::move(arg5) , boost::move(arg6) , boost::move(arg7) , boost::move(arg8) , boost::move(arg9) , boost::move(arg10) , boost::move(arg11) , boost::move(arg12) , boost::move(arg13) , boost::move(arg14) , boost::move(arg15));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args)) , util::get< 13>(boost::forward<Arguments>( args)) , util::get< 14>(boost::forward<Arguments>( args)) , util::get< 15>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function_void(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static util::unused_type
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_action" << 16
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args)) , util::get< 13>(boost::forward<Arguments>( args)) , util::get< 14>(boost::forward<Arguments>( args)) , util::get< 15>(boost::forward<Arguments>( args)));
            return util::unused;
        }
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15),
        typename Derived = detail::this_type>
    struct plain_action16
      : plain_base_action16<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15, F,
            typename detail::action_type<
                plain_action16<
                    T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_action16, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15), F, Derived, boost::mpl::false_>
      : plain_action16<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15, F, Derived>
    {
        typedef plain_action16<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15, F, Derived
        > type;
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15),
        typename Derived = detail::this_type>
    struct plain_direct_action16
      : plain_base_action16<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15, F,
            typename detail::action_type<
                plain_direct_action16<
                    T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_direct_action16, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15), F, Derived, boost::mpl::true_>
      : plain_direct_action16<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15, F, Derived>
    {
        typedef plain_direct_action16<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15), typename Derived>
    struct plain_result_action16<
                void, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15, F, Derived>
      : plain_action16<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15, F, Derived>
    {};
}}
namespace hpx { namespace traits
{
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14 , typename Arg15,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_action16<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14 , typename Arg15,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15), typename Derived,
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_action16<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14 , typename Arg15,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_result_action16<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14 , typename Arg15,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15), typename Derived, typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_result_action16<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
}}
namespace hpx { namespace actions
{
    
    
    template <
        typename Result,
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16), typename Derived>
    class plain_base_result_action17
      : public action<
            components::server::plain_function<Derived>,
            Result,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type , typename util::decay<T13>::type , typename util::decay<T14>::type , typename util::decay<T15>::type , typename util::decay<T16>::type>,
            Derived>
    {
    public:
        typedef Result result_type;
        typedef typename detail::remote_action_result<Result>::type
            remote_result_type;
        typedef hpx::util::tuple<
            typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type , typename util::decay<T13>::type , typename util::decay<T14>::type , typename util::decay<T15>::type , typename util::decay<T16>::type> arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14 , typename Arg15 , typename Arg16>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4 , BOOST_FWD_REF(Arg5) arg5 , BOOST_FWD_REF(Arg6) arg6 , BOOST_FWD_REF(Arg7) arg7 , BOOST_FWD_REF(Arg8) arg8 , BOOST_FWD_REF(Arg9) arg9 , BOOST_FWD_REF(Arg10) arg10 , BOOST_FWD_REF(Arg11) arg11 , BOOST_FWD_REF(Arg12) arg12 , BOOST_FWD_REF(Arg13) arg13 , BOOST_FWD_REF(Arg14) arg14 , BOOST_FWD_REF(Arg15) arg15 , BOOST_FWD_REF(Arg16) arg16) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4) , boost::move(arg5) , boost::move(arg6) , boost::move(arg7) , boost::move(arg8) , boost::move(arg9) , boost::move(arg10) , boost::move(arg11) , boost::move(arg12) , boost::move(arg13) , boost::move(arg14) , boost::move(arg15) , boost::move(arg16));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args)) , util::get< 13>(boost::forward<Arguments>( args)) , util::get< 14>(boost::forward<Arguments>( args)) , util::get< 15>(boost::forward<Arguments>( args)) , util::get< 16>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static Result
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_result_action" << 17
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            return F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args)) , util::get< 13>(boost::forward<Arguments>( args)) , util::get< 14>(boost::forward<Arguments>( args)) , util::get< 15>(boost::forward<Arguments>( args)) , util::get< 16>(boost::forward<Arguments>( args)));
        }
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16),
        typename Derived = detail::this_type>
    struct plain_result_action17
      : plain_base_result_action17<Result,
          T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16, F,
          typename detail::action_type<
              plain_result_action17<
                  Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_result_action17, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16), F, Derived, boost::mpl::false_>
      : plain_result_action17<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16, F, Derived>
    {
        typedef plain_result_action17<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16, F, Derived
        > type;
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16),
        typename Derived = detail::this_type>
    struct plain_direct_result_action17
      : plain_base_result_action17<Result,
          T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16, F,
          typename detail::action_type<
              plain_direct_result_action17<
                  Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_direct_result_action17, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16), F, Derived, boost::mpl::true_>
      : plain_direct_result_action17<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16, F, Derived>
    {
        typedef plain_direct_result_action17<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16), typename Derived>
    class plain_base_action17
      : public action<
            components::server::plain_function<Derived>,
            util::unused_type,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type , typename util::decay<T13>::type , typename util::decay<T14>::type , typename util::decay<T15>::type , typename util::decay<T16>::type>,
            Derived>
    {
    public:
        typedef util::unused_type result_type;
        typedef util::unused_type remote_result_type;
        typedef
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type , typename util::decay<T13>::type , typename util::decay<T14>::type , typename util::decay<T15>::type , typename util::decay<T16>::type>
        arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14 , typename Arg15 , typename Arg16>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4 , BOOST_FWD_REF(Arg5) arg5 , BOOST_FWD_REF(Arg6) arg6 , BOOST_FWD_REF(Arg7) arg7 , BOOST_FWD_REF(Arg8) arg8 , BOOST_FWD_REF(Arg9) arg9 , BOOST_FWD_REF(Arg10) arg10 , BOOST_FWD_REF(Arg11) arg11 , BOOST_FWD_REF(Arg12) arg12 , BOOST_FWD_REF(Arg13) arg13 , BOOST_FWD_REF(Arg14) arg14 , BOOST_FWD_REF(Arg15) arg15 , BOOST_FWD_REF(Arg16) arg16) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4) , boost::move(arg5) , boost::move(arg6) , boost::move(arg7) , boost::move(arg8) , boost::move(arg9) , boost::move(arg10) , boost::move(arg11) , boost::move(arg12) , boost::move(arg13) , boost::move(arg14) , boost::move(arg15) , boost::move(arg16));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args)) , util::get< 13>(boost::forward<Arguments>( args)) , util::get< 14>(boost::forward<Arguments>( args)) , util::get< 15>(boost::forward<Arguments>( args)) , util::get< 16>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function_void(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static util::unused_type
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_action" << 17
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args)) , util::get< 13>(boost::forward<Arguments>( args)) , util::get< 14>(boost::forward<Arguments>( args)) , util::get< 15>(boost::forward<Arguments>( args)) , util::get< 16>(boost::forward<Arguments>( args)));
            return util::unused;
        }
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16),
        typename Derived = detail::this_type>
    struct plain_action17
      : plain_base_action17<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16, F,
            typename detail::action_type<
                plain_action17<
                    T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_action17, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16), F, Derived, boost::mpl::false_>
      : plain_action17<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16, F, Derived>
    {
        typedef plain_action17<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16, F, Derived
        > type;
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16),
        typename Derived = detail::this_type>
    struct plain_direct_action17
      : plain_base_action17<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16, F,
            typename detail::action_type<
                plain_direct_action17<
                    T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_direct_action17, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16), F, Derived, boost::mpl::true_>
      : plain_direct_action17<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16, F, Derived>
    {
        typedef plain_direct_action17<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16), typename Derived>
    struct plain_result_action17<
                void, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16, F, Derived>
      : plain_action17<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16, F, Derived>
    {};
}}
namespace hpx { namespace traits
{
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14 , typename Arg15 , typename Arg16,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_action17<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14 , typename Arg15 , typename Arg16,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16), typename Derived,
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_action17<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14 , typename Arg15 , typename Arg16,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_result_action17<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14 , typename Arg15 , typename Arg16,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16), typename Derived, typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_result_action17<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
}}
namespace hpx { namespace actions
{
    
    
    template <
        typename Result,
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17), typename Derived>
    class plain_base_result_action18
      : public action<
            components::server::plain_function<Derived>,
            Result,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type , typename util::decay<T13>::type , typename util::decay<T14>::type , typename util::decay<T15>::type , typename util::decay<T16>::type , typename util::decay<T17>::type>,
            Derived>
    {
    public:
        typedef Result result_type;
        typedef typename detail::remote_action_result<Result>::type
            remote_result_type;
        typedef hpx::util::tuple<
            typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type , typename util::decay<T13>::type , typename util::decay<T14>::type , typename util::decay<T15>::type , typename util::decay<T16>::type , typename util::decay<T17>::type> arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14 , typename Arg15 , typename Arg16 , typename Arg17>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4 , BOOST_FWD_REF(Arg5) arg5 , BOOST_FWD_REF(Arg6) arg6 , BOOST_FWD_REF(Arg7) arg7 , BOOST_FWD_REF(Arg8) arg8 , BOOST_FWD_REF(Arg9) arg9 , BOOST_FWD_REF(Arg10) arg10 , BOOST_FWD_REF(Arg11) arg11 , BOOST_FWD_REF(Arg12) arg12 , BOOST_FWD_REF(Arg13) arg13 , BOOST_FWD_REF(Arg14) arg14 , BOOST_FWD_REF(Arg15) arg15 , BOOST_FWD_REF(Arg16) arg16 , BOOST_FWD_REF(Arg17) arg17) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4) , boost::move(arg5) , boost::move(arg6) , boost::move(arg7) , boost::move(arg8) , boost::move(arg9) , boost::move(arg10) , boost::move(arg11) , boost::move(arg12) , boost::move(arg13) , boost::move(arg14) , boost::move(arg15) , boost::move(arg16) , boost::move(arg17));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args)) , util::get< 13>(boost::forward<Arguments>( args)) , util::get< 14>(boost::forward<Arguments>( args)) , util::get< 15>(boost::forward<Arguments>( args)) , util::get< 16>(boost::forward<Arguments>( args)) , util::get< 17>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static Result
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_result_action" << 18
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            return F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args)) , util::get< 13>(boost::forward<Arguments>( args)) , util::get< 14>(boost::forward<Arguments>( args)) , util::get< 15>(boost::forward<Arguments>( args)) , util::get< 16>(boost::forward<Arguments>( args)) , util::get< 17>(boost::forward<Arguments>( args)));
        }
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17),
        typename Derived = detail::this_type>
    struct plain_result_action18
      : plain_base_result_action18<Result,
          T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17, F,
          typename detail::action_type<
              plain_result_action18<
                  Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_result_action18, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17), F, Derived, boost::mpl::false_>
      : plain_result_action18<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17, F, Derived>
    {
        typedef plain_result_action18<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17, F, Derived
        > type;
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17),
        typename Derived = detail::this_type>
    struct plain_direct_result_action18
      : plain_base_result_action18<Result,
          T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17, F,
          typename detail::action_type<
              plain_direct_result_action18<
                  Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_direct_result_action18, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17), F, Derived, boost::mpl::true_>
      : plain_direct_result_action18<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17, F, Derived>
    {
        typedef plain_direct_result_action18<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17), typename Derived>
    class plain_base_action18
      : public action<
            components::server::plain_function<Derived>,
            util::unused_type,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type , typename util::decay<T13>::type , typename util::decay<T14>::type , typename util::decay<T15>::type , typename util::decay<T16>::type , typename util::decay<T17>::type>,
            Derived>
    {
    public:
        typedef util::unused_type result_type;
        typedef util::unused_type remote_result_type;
        typedef
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type , typename util::decay<T13>::type , typename util::decay<T14>::type , typename util::decay<T15>::type , typename util::decay<T16>::type , typename util::decay<T17>::type>
        arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14 , typename Arg15 , typename Arg16 , typename Arg17>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4 , BOOST_FWD_REF(Arg5) arg5 , BOOST_FWD_REF(Arg6) arg6 , BOOST_FWD_REF(Arg7) arg7 , BOOST_FWD_REF(Arg8) arg8 , BOOST_FWD_REF(Arg9) arg9 , BOOST_FWD_REF(Arg10) arg10 , BOOST_FWD_REF(Arg11) arg11 , BOOST_FWD_REF(Arg12) arg12 , BOOST_FWD_REF(Arg13) arg13 , BOOST_FWD_REF(Arg14) arg14 , BOOST_FWD_REF(Arg15) arg15 , BOOST_FWD_REF(Arg16) arg16 , BOOST_FWD_REF(Arg17) arg17) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4) , boost::move(arg5) , boost::move(arg6) , boost::move(arg7) , boost::move(arg8) , boost::move(arg9) , boost::move(arg10) , boost::move(arg11) , boost::move(arg12) , boost::move(arg13) , boost::move(arg14) , boost::move(arg15) , boost::move(arg16) , boost::move(arg17));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args)) , util::get< 13>(boost::forward<Arguments>( args)) , util::get< 14>(boost::forward<Arguments>( args)) , util::get< 15>(boost::forward<Arguments>( args)) , util::get< 16>(boost::forward<Arguments>( args)) , util::get< 17>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function_void(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static util::unused_type
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_action" << 18
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args)) , util::get< 13>(boost::forward<Arguments>( args)) , util::get< 14>(boost::forward<Arguments>( args)) , util::get< 15>(boost::forward<Arguments>( args)) , util::get< 16>(boost::forward<Arguments>( args)) , util::get< 17>(boost::forward<Arguments>( args)));
            return util::unused;
        }
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17),
        typename Derived = detail::this_type>
    struct plain_action18
      : plain_base_action18<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17, F,
            typename detail::action_type<
                plain_action18<
                    T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_action18, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17), F, Derived, boost::mpl::false_>
      : plain_action18<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17, F, Derived>
    {
        typedef plain_action18<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17, F, Derived
        > type;
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17),
        typename Derived = detail::this_type>
    struct plain_direct_action18
      : plain_base_action18<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17, F,
            typename detail::action_type<
                plain_direct_action18<
                    T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_direct_action18, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17), F, Derived, boost::mpl::true_>
      : plain_direct_action18<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17, F, Derived>
    {
        typedef plain_direct_action18<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17), typename Derived>
    struct plain_result_action18<
                void, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17, F, Derived>
      : plain_action18<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17, F, Derived>
    {};
}}
namespace hpx { namespace traits
{
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14 , typename Arg15 , typename Arg16 , typename Arg17,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16 , Arg17), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_action18<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16 , Arg17, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14 , typename Arg15 , typename Arg16 , typename Arg17,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16 , Arg17), typename Derived,
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_action18<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16 , Arg17, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14 , typename Arg15 , typename Arg16 , typename Arg17,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16 , Arg17), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_result_action18<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16 , Arg17, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14 , typename Arg15 , typename Arg16 , typename Arg17,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16 , Arg17), typename Derived, typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_result_action18<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16 , Arg17, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
}}
namespace hpx { namespace actions
{
    
    
    template <
        typename Result,
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17 , typename T18,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18), typename Derived>
    class plain_base_result_action19
      : public action<
            components::server::plain_function<Derived>,
            Result,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type , typename util::decay<T13>::type , typename util::decay<T14>::type , typename util::decay<T15>::type , typename util::decay<T16>::type , typename util::decay<T17>::type , typename util::decay<T18>::type>,
            Derived>
    {
    public:
        typedef Result result_type;
        typedef typename detail::remote_action_result<Result>::type
            remote_result_type;
        typedef hpx::util::tuple<
            typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type , typename util::decay<T13>::type , typename util::decay<T14>::type , typename util::decay<T15>::type , typename util::decay<T16>::type , typename util::decay<T17>::type , typename util::decay<T18>::type> arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14 , typename Arg15 , typename Arg16 , typename Arg17 , typename Arg18>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4 , BOOST_FWD_REF(Arg5) arg5 , BOOST_FWD_REF(Arg6) arg6 , BOOST_FWD_REF(Arg7) arg7 , BOOST_FWD_REF(Arg8) arg8 , BOOST_FWD_REF(Arg9) arg9 , BOOST_FWD_REF(Arg10) arg10 , BOOST_FWD_REF(Arg11) arg11 , BOOST_FWD_REF(Arg12) arg12 , BOOST_FWD_REF(Arg13) arg13 , BOOST_FWD_REF(Arg14) arg14 , BOOST_FWD_REF(Arg15) arg15 , BOOST_FWD_REF(Arg16) arg16 , BOOST_FWD_REF(Arg17) arg17 , BOOST_FWD_REF(Arg18) arg18) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4) , boost::move(arg5) , boost::move(arg6) , boost::move(arg7) , boost::move(arg8) , boost::move(arg9) , boost::move(arg10) , boost::move(arg11) , boost::move(arg12) , boost::move(arg13) , boost::move(arg14) , boost::move(arg15) , boost::move(arg16) , boost::move(arg17) , boost::move(arg18));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args)) , util::get< 13>(boost::forward<Arguments>( args)) , util::get< 14>(boost::forward<Arguments>( args)) , util::get< 15>(boost::forward<Arguments>( args)) , util::get< 16>(boost::forward<Arguments>( args)) , util::get< 17>(boost::forward<Arguments>( args)) , util::get< 18>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static Result
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_result_action" << 19
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            return F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args)) , util::get< 13>(boost::forward<Arguments>( args)) , util::get< 14>(boost::forward<Arguments>( args)) , util::get< 15>(boost::forward<Arguments>( args)) , util::get< 16>(boost::forward<Arguments>( args)) , util::get< 17>(boost::forward<Arguments>( args)) , util::get< 18>(boost::forward<Arguments>( args)));
        }
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17 , typename T18,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18),
        typename Derived = detail::this_type>
    struct plain_result_action19
      : plain_base_result_action19<Result,
          T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18, F,
          typename detail::action_type<
              plain_result_action19<
                  Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_result_action19, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17 , typename T18,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18), F, Derived, boost::mpl::false_>
      : plain_result_action19<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18, F, Derived>
    {
        typedef plain_result_action19<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18, F, Derived
        > type;
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17 , typename T18,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18),
        typename Derived = detail::this_type>
    struct plain_direct_result_action19
      : plain_base_result_action19<Result,
          T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18, F,
          typename detail::action_type<
              plain_direct_result_action19<
                  Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_direct_result_action19, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17 , typename T18,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18), F, Derived, boost::mpl::true_>
      : plain_direct_result_action19<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18, F, Derived>
    {
        typedef plain_direct_result_action19<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17 , typename T18,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18), typename Derived>
    class plain_base_action19
      : public action<
            components::server::plain_function<Derived>,
            util::unused_type,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type , typename util::decay<T13>::type , typename util::decay<T14>::type , typename util::decay<T15>::type , typename util::decay<T16>::type , typename util::decay<T17>::type , typename util::decay<T18>::type>,
            Derived>
    {
    public:
        typedef util::unused_type result_type;
        typedef util::unused_type remote_result_type;
        typedef
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type , typename util::decay<T13>::type , typename util::decay<T14>::type , typename util::decay<T15>::type , typename util::decay<T16>::type , typename util::decay<T17>::type , typename util::decay<T18>::type>
        arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14 , typename Arg15 , typename Arg16 , typename Arg17 , typename Arg18>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4 , BOOST_FWD_REF(Arg5) arg5 , BOOST_FWD_REF(Arg6) arg6 , BOOST_FWD_REF(Arg7) arg7 , BOOST_FWD_REF(Arg8) arg8 , BOOST_FWD_REF(Arg9) arg9 , BOOST_FWD_REF(Arg10) arg10 , BOOST_FWD_REF(Arg11) arg11 , BOOST_FWD_REF(Arg12) arg12 , BOOST_FWD_REF(Arg13) arg13 , BOOST_FWD_REF(Arg14) arg14 , BOOST_FWD_REF(Arg15) arg15 , BOOST_FWD_REF(Arg16) arg16 , BOOST_FWD_REF(Arg17) arg17 , BOOST_FWD_REF(Arg18) arg18) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4) , boost::move(arg5) , boost::move(arg6) , boost::move(arg7) , boost::move(arg8) , boost::move(arg9) , boost::move(arg10) , boost::move(arg11) , boost::move(arg12) , boost::move(arg13) , boost::move(arg14) , boost::move(arg15) , boost::move(arg16) , boost::move(arg17) , boost::move(arg18));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args)) , util::get< 13>(boost::forward<Arguments>( args)) , util::get< 14>(boost::forward<Arguments>( args)) , util::get< 15>(boost::forward<Arguments>( args)) , util::get< 16>(boost::forward<Arguments>( args)) , util::get< 17>(boost::forward<Arguments>( args)) , util::get< 18>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function_void(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static util::unused_type
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_action" << 19
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args)) , util::get< 13>(boost::forward<Arguments>( args)) , util::get< 14>(boost::forward<Arguments>( args)) , util::get< 15>(boost::forward<Arguments>( args)) , util::get< 16>(boost::forward<Arguments>( args)) , util::get< 17>(boost::forward<Arguments>( args)) , util::get< 18>(boost::forward<Arguments>( args)));
            return util::unused;
        }
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17 , typename T18,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18),
        typename Derived = detail::this_type>
    struct plain_action19
      : plain_base_action19<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18, F,
            typename detail::action_type<
                plain_action19<
                    T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_action19, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17 , typename T18,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18), F, Derived, boost::mpl::false_>
      : plain_action19<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18, F, Derived>
    {
        typedef plain_action19<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18, F, Derived
        > type;
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17 , typename T18,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18),
        typename Derived = detail::this_type>
    struct plain_direct_action19
      : plain_base_action19<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18, F,
            typename detail::action_type<
                plain_direct_action19<
                    T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_direct_action19, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17 , typename T18,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18), F, Derived, boost::mpl::true_>
      : plain_direct_action19<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18, F, Derived>
    {
        typedef plain_direct_action19<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17 , typename T18,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18), typename Derived>
    struct plain_result_action19<
                void, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18, F, Derived>
      : plain_action19<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18, F, Derived>
    {};
}}
namespace hpx { namespace traits
{
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14 , typename Arg15 , typename Arg16 , typename Arg17 , typename Arg18,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16 , Arg17 , Arg18), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_action19<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16 , Arg17 , Arg18, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14 , typename Arg15 , typename Arg16 , typename Arg17 , typename Arg18,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16 , Arg17 , Arg18), typename Derived,
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_action19<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16 , Arg17 , Arg18, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14 , typename Arg15 , typename Arg16 , typename Arg17 , typename Arg18,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16 , Arg17 , Arg18), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_result_action19<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16 , Arg17 , Arg18, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14 , typename Arg15 , typename Arg16 , typename Arg17 , typename Arg18,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16 , Arg17 , Arg18), typename Derived, typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_result_action19<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16 , Arg17 , Arg18, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
}}
namespace hpx { namespace actions
{
    
    
    template <
        typename Result,
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17 , typename T18 , typename T19,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19), typename Derived>
    class plain_base_result_action20
      : public action<
            components::server::plain_function<Derived>,
            Result,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type , typename util::decay<T13>::type , typename util::decay<T14>::type , typename util::decay<T15>::type , typename util::decay<T16>::type , typename util::decay<T17>::type , typename util::decay<T18>::type , typename util::decay<T19>::type>,
            Derived>
    {
    public:
        typedef Result result_type;
        typedef typename detail::remote_action_result<Result>::type
            remote_result_type;
        typedef hpx::util::tuple<
            typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type , typename util::decay<T13>::type , typename util::decay<T14>::type , typename util::decay<T15>::type , typename util::decay<T16>::type , typename util::decay<T17>::type , typename util::decay<T18>::type , typename util::decay<T19>::type> arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14 , typename Arg15 , typename Arg16 , typename Arg17 , typename Arg18 , typename Arg19>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4 , BOOST_FWD_REF(Arg5) arg5 , BOOST_FWD_REF(Arg6) arg6 , BOOST_FWD_REF(Arg7) arg7 , BOOST_FWD_REF(Arg8) arg8 , BOOST_FWD_REF(Arg9) arg9 , BOOST_FWD_REF(Arg10) arg10 , BOOST_FWD_REF(Arg11) arg11 , BOOST_FWD_REF(Arg12) arg12 , BOOST_FWD_REF(Arg13) arg13 , BOOST_FWD_REF(Arg14) arg14 , BOOST_FWD_REF(Arg15) arg15 , BOOST_FWD_REF(Arg16) arg16 , BOOST_FWD_REF(Arg17) arg17 , BOOST_FWD_REF(Arg18) arg18 , BOOST_FWD_REF(Arg19) arg19) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4) , boost::move(arg5) , boost::move(arg6) , boost::move(arg7) , boost::move(arg8) , boost::move(arg9) , boost::move(arg10) , boost::move(arg11) , boost::move(arg12) , boost::move(arg13) , boost::move(arg14) , boost::move(arg15) , boost::move(arg16) , boost::move(arg17) , boost::move(arg18) , boost::move(arg19));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args)) , util::get< 13>(boost::forward<Arguments>( args)) , util::get< 14>(boost::forward<Arguments>( args)) , util::get< 15>(boost::forward<Arguments>( args)) , util::get< 16>(boost::forward<Arguments>( args)) , util::get< 17>(boost::forward<Arguments>( args)) , util::get< 18>(boost::forward<Arguments>( args)) , util::get< 19>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static Result
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_result_action" << 20
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            return F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args)) , util::get< 13>(boost::forward<Arguments>( args)) , util::get< 14>(boost::forward<Arguments>( args)) , util::get< 15>(boost::forward<Arguments>( args)) , util::get< 16>(boost::forward<Arguments>( args)) , util::get< 17>(boost::forward<Arguments>( args)) , util::get< 18>(boost::forward<Arguments>( args)) , util::get< 19>(boost::forward<Arguments>( args)));
        }
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17 , typename T18 , typename T19,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19),
        typename Derived = detail::this_type>
    struct plain_result_action20
      : plain_base_result_action20<Result,
          T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19, F,
          typename detail::action_type<
              plain_result_action20<
                  Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_result_action20, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17 , typename T18 , typename T19,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19), F, Derived, boost::mpl::false_>
      : plain_result_action20<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19, F, Derived>
    {
        typedef plain_result_action20<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19, F, Derived
        > type;
    };
    
    
    template <
        typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17 , typename T18 , typename T19,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19),
        typename Derived = detail::this_type>
    struct plain_direct_result_action20
      : plain_base_result_action20<Result,
          T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19, F,
          typename detail::action_type<
              plain_direct_result_action20<
                  Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19, F>, Derived
          >::type>
    {
        typedef typename detail::action_type<
            plain_direct_result_action20, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename Result, typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17 , typename T18 , typename T19,
        Result (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19), typename Derived>
    struct make_action<Result (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19), F, Derived, boost::mpl::true_>
      : plain_direct_result_action20<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19, F, Derived>
    {
        typedef plain_direct_result_action20<
            Result, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17 , typename T18 , typename T19,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19), typename Derived>
    class plain_base_action20
      : public action<
            components::server::plain_function<Derived>,
            util::unused_type,
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type , typename util::decay<T13>::type , typename util::decay<T14>::type , typename util::decay<T15>::type , typename util::decay<T16>::type , typename util::decay<T17>::type , typename util::decay<T18>::type , typename util::decay<T19>::type>,
            Derived>
    {
    public:
        typedef util::unused_type result_type;
        typedef util::unused_type remote_result_type;
        typedef
            hpx::util::tuple<typename util::decay<T0>::type , typename util::decay<T1>::type , typename util::decay<T2>::type , typename util::decay<T3>::type , typename util::decay<T4>::type , typename util::decay<T5>::type , typename util::decay<T6>::type , typename util::decay<T7>::type , typename util::decay<T8>::type , typename util::decay<T9>::type , typename util::decay<T10>::type , typename util::decay<T11>::type , typename util::decay<T12>::type , typename util::decay<T13>::type , typename util::decay<T14>::type , typename util::decay<T15>::type , typename util::decay<T16>::type , typename util::decay<T17>::type , typename util::decay<T18>::type , typename util::decay<T19>::type>
        arguments_type;
        typedef action<
            components::server::plain_function<Derived>, remote_result_type,
            arguments_type, Derived> base_type;
        
        static bool is_target_valid(naming::id_type const& id)
        {
            return naming::is_locality(id);
        }
    protected:
        
        
        
        struct thread_function
        {
            typedef threads::thread_state_enum result_type;
            template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14 , typename Arg15 , typename Arg16 , typename Arg17 , typename Arg18 , typename Arg19>
            BOOST_FORCEINLINE result_type operator()(
                BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4 , BOOST_FWD_REF(Arg5) arg5 , BOOST_FWD_REF(Arg6) arg6 , BOOST_FWD_REF(Arg7) arg7 , BOOST_FWD_REF(Arg8) arg8 , BOOST_FWD_REF(Arg9) arg9 , BOOST_FWD_REF(Arg10) arg10 , BOOST_FWD_REF(Arg11) arg11 , BOOST_FWD_REF(Arg12) arg12 , BOOST_FWD_REF(Arg13) arg13 , BOOST_FWD_REF(Arg14) arg14 , BOOST_FWD_REF(Arg15) arg15 , BOOST_FWD_REF(Arg16) arg16 , BOOST_FWD_REF(Arg17) arg17 , BOOST_FWD_REF(Arg18) arg18 , BOOST_FWD_REF(Arg19) arg19) const
            {
                try {
                    LTM_(debug) << "Executing plain action("
                                << detail::get_action_name<Derived>()
                                << ").";
                    
                    
                    
                    
                    
                    F(boost::move(arg0) , boost::move(arg1) , boost::move(arg2) , boost::move(arg3) , boost::move(arg4) , boost::move(arg5) , boost::move(arg6) , boost::move(arg7) , boost::move(arg8) , boost::move(arg9) , boost::move(arg10) , boost::move(arg11) , boost::move(arg12) , boost::move(arg13) , boost::move(arg14) , boost::move(arg15) , boost::move(arg16) , boost::move(arg17) , boost::move(arg18) , boost::move(arg19));
                }
                catch (hpx::exception const& e) {
                    if (e.get_error() != hpx::thread_interrupted) {
                        LTM_(error)
                            << "Unhandled exception while executing plain action("
                            << detail::get_action_name<Derived>()
                            << "): " << e.what();
                        
                        hpx::report_error(boost::current_exception());
                    }
                }
                catch (...) {
                    LTM_(error)
                        << "Unhandled exception while executing plain action("
                        << detail::get_action_name<Derived>() << ")";
                    
                    hpx::report_error(boost::current_exception());
                }
                
                
                
                util::force_error_on_lock();
                return threads::terminated;
            }
        };
    public:
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                HPX_STD_BIND(typename Derived::thread_function(),
                    util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args)) , util::get< 13>(boost::forward<Arguments>( args)) , util::get< 14>(boost::forward<Arguments>( args)) , util::get< 15>(boost::forward<Arguments>( args)) , util::get< 16>(boost::forward<Arguments>( args)) , util::get< 17>(boost::forward<Arguments>( args)) , util::get< 18>(boost::forward<Arguments>( args)) , util::get< 19>(boost::forward<Arguments>( args))), lva));
        }
        
        
        
        
        template <typename Arguments>
        static HPX_STD_FUNCTION<threads::thread_function_type>
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, BOOST_FWD_REF(Arguments) args)
        {
            return boost::move(Derived::decorate_action(
                base_type::construct_continuation_thread_function_void(
                    cont, F, boost::forward<Arguments>(args)), lva));
        }
        
        template <typename Arguments>
        BOOST_FORCEINLINE static util::unused_type
        execute_function(naming::address::address_type lva,
            BOOST_FWD_REF(Arguments) args)
        {
            LTM_(debug)
                << "plain_base_action" << 20
                << "::execute_function name("
                << detail::get_action_name<Derived>() << ")";
            F(util::get< 0>(boost::forward<Arguments>( args)) , util::get< 1>(boost::forward<Arguments>( args)) , util::get< 2>(boost::forward<Arguments>( args)) , util::get< 3>(boost::forward<Arguments>( args)) , util::get< 4>(boost::forward<Arguments>( args)) , util::get< 5>(boost::forward<Arguments>( args)) , util::get< 6>(boost::forward<Arguments>( args)) , util::get< 7>(boost::forward<Arguments>( args)) , util::get< 8>(boost::forward<Arguments>( args)) , util::get< 9>(boost::forward<Arguments>( args)) , util::get< 10>(boost::forward<Arguments>( args)) , util::get< 11>(boost::forward<Arguments>( args)) , util::get< 12>(boost::forward<Arguments>( args)) , util::get< 13>(boost::forward<Arguments>( args)) , util::get< 14>(boost::forward<Arguments>( args)) , util::get< 15>(boost::forward<Arguments>( args)) , util::get< 16>(boost::forward<Arguments>( args)) , util::get< 17>(boost::forward<Arguments>( args)) , util::get< 18>(boost::forward<Arguments>( args)) , util::get< 19>(boost::forward<Arguments>( args)));
            return util::unused;
        }
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17 , typename T18 , typename T19,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19),
        typename Derived = detail::this_type>
    struct plain_action20
      : plain_base_action20<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19, F,
            typename detail::action_type<
                plain_action20<
                    T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_action20, Derived
        >::type derived_type;
        typedef boost::mpl::false_ direct_execution;
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17 , typename T18 , typename T19,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19), F, Derived, boost::mpl::false_>
      : plain_action20<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19, F, Derived>
    {
        typedef plain_action20<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19, F, Derived
        > type;
    };
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17 , typename T18 , typename T19,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19),
        typename Derived = detail::this_type>
    struct plain_direct_action20
      : plain_base_action20<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19, F,
            typename detail::action_type<
                plain_direct_action20<
                    T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19, F>, Derived
            >::type>
    {
        typedef typename detail::action_type<
            plain_direct_action20, Derived
        >::type derived_type;
        typedef boost::mpl::true_ direct_execution;
        
        
        static base_action::action_type get_action_type()
        {
            return base_action::direct_action;
        }
    };
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17 , typename T18 , typename T19,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19), typename Derived>
    struct make_action<void (*)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19), F, Derived, boost::mpl::true_>
      : plain_direct_action20<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19, F, Derived>
    {
        typedef plain_direct_action20<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19, F, Derived
        > type;
    };
    
    
    template <
        typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17 , typename T18 , typename T19,
        void (*F)(T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19), typename Derived>
    struct plain_result_action20<
                void, T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19, F, Derived>
      : plain_action20<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19, F, Derived>
    {};
}}
namespace hpx { namespace traits
{
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14 , typename Arg15 , typename Arg16 , typename Arg17 , typename Arg18 , typename Arg19,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16 , Arg17 , Arg18 , Arg19), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_action20<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16 , Arg17 , Arg18 , Arg19, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14 , typename Arg15 , typename Arg16 , typename Arg17 , typename Arg18 , typename Arg19,
        void (*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16 , Arg17 , Arg18 , Arg19), typename Derived,
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_action20<
                    Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16 , Arg17 , Arg18 , Arg19, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14 , typename Arg15 , typename Arg16 , typename Arg17 , typename Arg18 , typename Arg19,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16 , Arg17 , Arg18 , Arg19), typename Derived, 
        typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_result_action20<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16 , Arg17 , Arg18 , Arg19, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
    template <typename R, typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4 , typename Arg5 , typename Arg6 , typename Arg7 , typename Arg8 , typename Arg9 , typename Arg10 , typename Arg11 , typename Arg12 , typename Arg13 , typename Arg14 , typename Arg15 , typename Arg16 , typename Arg17 , typename Arg18 , typename Arg19,
        R(*F)(Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16 , Arg17 , Arg18 , Arg19), typename Derived, typename Enable>
    struct needs_guid_initialization<
            hpx::actions::transfer_action<
                hpx::actions::plain_direct_result_action20<
                    R, Arg0 , Arg1 , Arg2 , Arg3 , Arg4 , Arg5 , Arg6 , Arg7 , Arg8 , Arg9 , Arg10 , Arg11 , Arg12 , Arg13 , Arg14 , Arg15 , Arg16 , Arg17 , Arg18 , Arg19, F, Derived> >, Enable>
      : boost::mpl::false_
    {};
}}
